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

}";

fn get_starter_code(id: &str) -> String {
    format!(
        "
use crate::common::read_line;
use std::io::{{BufRead, Error, Write}};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {{
    let lines: usize = read_line(reader)?;
  

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
    //check if dir exists
    let parent_path = "src/code_forces";
    let rank_path = format!("{parent_path}/rank_{rank}");
    let dir_exists: bool = std::path::Path::new(&rank_path).is_dir();

    let mod_path = format!("{rank_path}/mod.rs");
    if !dir_exists {
        // create dir
        let _ = std::fs::create_dir(&rank_path);

        //if the dir didnt exit it was not registerd in code_forces/mod.rs
        let mod_file_content2 = format!("pub mod rank_{rank};");
        let mut parent_mod_file = OpenOptions::new()
            .write(true)
            .append(true)
            .open("src/code_forces/mod.rs")
            .unwrap();
        let _ = writeln!(parent_mod_file, "{mod_file_content2}");

        // we also needs to create code_forces/rank_????/mod.rs

        let _ = std::fs::File::create(&mod_path); //something is missing here
    }

    let mod_file_content = format!("pub mod {name};");

    let mut parent_mod_file = OpenOptions::new()
        .write(true)
        .append(true)
        .open(mod_path)
        .unwrap();
    let _ = writeln!(parent_mod_file, "{mod_file_content}");

    //std::fs::write(&mod_path, mod_file_content).expect("Unable to write file");

    let name_path = format!("{rank_path}/{name}.rs");
    let _ = std::fs::File::create(&name_path);
    std::fs::write(&name_path, get_starter_code(id)).expect("Unable to write file");
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
    let formatted_name = format!("{name}_{id}")
        .to_lowercase()
        .replace(" ", "_")
        .replace("-", "_");

    let parent_path = "src/code_forces";
    let path = format!("{parent_path}/rank_{rank}/{formatted_name}.rs");
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
            let helper_file_path = format!("src/common/{}.rs", helper_name);
            let helper_file = File::open(helper_file_path).unwrap();
            let helper_lines = io::BufReader::new(helper_file).lines();
            for helper_line in helper_lines {
                let helper_line = helper_line.expect("reading  helper line");
                let _ = writeln!(output_file, "{helper_line}");
            }
            let _ = writeln!(output_file, "");
        } else if line == "#[allow(dead_code)]" {
            //skip line
        } else if line == "#[cfg(test)]" {
            break;
        } else {
            let _ = writeln!(output_file, "{line}");
        }
    }
}
