mod code_forces;

fn main() {
    let stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let _ = get_solution(&mut stdin.lock(), &mut stdout);
    std::io::Write::flush(&mut stdout).unwrap();
}

use std::io::{BufRead, Error, Write};

pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;
    writeln!(writer, "Answer")?;

    Ok(())
}
