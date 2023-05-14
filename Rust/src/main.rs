pub mod code_forces;
pub mod common;
use std::env;
use std::fs::{File, OpenOptions};
use std::io::{self, prelude::*};

const MAIN_FUNCTION: &str = "fn main() {
    let stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let _ = get_solution(&mut stdin.lock(), &mut stdout);
    std::io::Write::flush(&mut stdout).unwrap();
}

";

fn get_starter_code(rank: &str, name: &str, id: &str) -> String {
    format!(
        "
// cargo run {rank} {name} {id}
use crate::common::read_line;
use std::io::{{BufRead, Error, Write}};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {{
    let test_cases: usize = read_line(reader)?;
  

    Ok(())
}}

#[cfg(test)]
mod tests_{id} {{
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_3_cases() {{
        let input = \"\";
        let expected_output = \"\";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }}
}}
"
    )
}

fn create_path_and_file(rank: &str, name: &str, id: &str) {
    let parent_path = "src/code_forces";
    let rank_path = format!("{parent_path}/rank_{rank}");
    let dir_exists: bool = std::path::Path::new(&rank_path).is_dir();

    let mod_path = format!("{rank_path}/mod.rs");
    if !dir_exists {
        let _ = std::fs::create_dir(&rank_path);
        let _ = std::fs::File::create(&mod_path);

        let mut parent_mod_file = OpenOptions::new()
            .write(true)
            .append(true)
            .open("src/code_forces/mod.rs")
            .unwrap();
        let parent_mod_file_content = format!("pub mod rank_{rank};");
        let _ = writeln!(parent_mod_file, "{parent_mod_file_content}");
    }

    let mod_file_content = format!("pub mod {name}_{id};");

    let mut parent_mod_file = OpenOptions::new()
        .write(true)
        .append(true)
        .open(mod_path)
        .unwrap();
    let _ = writeln!(parent_mod_file, "{mod_file_content}");

    let name_path = format!("{rank_path}/{name}_{id}.rs");
    let _ = std::fs::File::create(&name_path);
    std::fs::write(&name_path, get_starter_code(rank, name, id)).expect("Unable to write file");
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 4 {
        println!("Please enter rank and problem name and id");
        return;
    }
    let rank = &args[1];
    let name = &args[2];
    let id = &args[3];
    let id = id.to_lowercase();
    let formatted_name = format!("{name}")
        .to_lowercase()
        .replace(" ", "_")
        .replace("-", "_");

    let parent_path = "src/code_forces";
    let path = format!("{parent_path}/rank_{rank}/{formatted_name}_{id}.rs");
    let file = File::open(&path);

    if file.is_err() {
        create_path_and_file(&rank, &formatted_name, &id);
    }

    let file = File::open(path);
    let input_file = file.expect("File and path should have been created");

    let output_file = File::open("output.rs");
    let _ = match output_file {
        Ok(file) => file,
        Err(_) => std::fs::File::create("output.rs").unwrap(),
    };

    let mut output_file = OpenOptions::new()
        .write(true)
        .append(true)
        .open("output.rs")
        .unwrap();

    std::fs::write("output.rs", MAIN_FUNCTION).expect("Unable to write file");

    let lines = io::BufReader::new(input_file).lines();
    for line in lines {
        let line = line.expect("reading line");

        if line.starts_with("use crate::common") {
            let helper_name = line.split("::").last().unwrap().trim_end_matches(';');

            if helper_name.starts_with('{') {
                //multiple helper functions
                let result = &helper_name[1..helper_name.len() - 1];
                let functions: Vec<&str> = result.split(", ").collect();

                for function in functions {
                    let helper_file_path = format!("src/common/{}.rs", function);
                    let helper_file = File::open(helper_file_path).unwrap();
                    let helper_lines = io::BufReader::new(helper_file).lines();
                    for helper_line in helper_lines {
                        let helper_line = helper_line.expect("reading  helper line");
                        let _ = writeln!(output_file, "{helper_line}");
                    }
                    let _ = writeln!(output_file, "");
                }
            } else {
                let helper_file_path = format!("src/common/{}.rs", helper_name);
                let helper_file = File::open(helper_file_path).unwrap();
                let helper_lines = io::BufReader::new(helper_file).lines();
                for helper_line in helper_lines {
                    let helper_line = helper_line.expect("reading  helper line");
                    let _ = writeln!(output_file, "{helper_line}");
                }
                let _ = writeln!(output_file, "");
            }
        } else if line == "#[allow(dead_code)]" || line.trim().starts_with("//") {
            //skip line
        } else if line == "#[cfg(test)]" {
            break;
        } else {
            let _ = writeln!(output_file, "{line}");
        }
    }
}
