use std::{
    io::{BufRead, Error, ErrorKind},
    str::FromStr,
};

pub fn read_line<R: BufRead, T: FromStr>(reader: &mut R) -> Result<T, Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;
    match lines.trim().parse::<T>() {
        Ok(val) => Ok(val),
        Err(_) => Err(Error::new(ErrorKind::Other, "Parsing failed")),
    }
}
