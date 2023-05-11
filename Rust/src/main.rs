mod code_forces;
mod common;

fn main() {
    let stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let _ = get_solution(&mut stdin.lock(), &mut stdout);
    std::io::Write::flush(&mut stdout).unwrap();
}

use std::{
    io::{BufRead, Error, ErrorKind, Write},
    str::FromStr,
};

fn read_line<R: BufRead, T: FromStr>(reader: &mut R) -> Result<T, Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;
    match lines.trim().parse::<T>() {
        Ok(val) => Ok(val),
        Err(_) => Err(Error::new(ErrorKind::Other, "Parsing failed")),
    }
}

pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let lines: String = read_line(reader)?;
    writeln!(writer, "{lines}")?;

    Ok(())
}
