pub fn read_line<R: std::io::BufRead, T: std::str::FromStr>(
    reader: &mut R,
) -> Result<T, std::io::Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;
    match lines.trim().parse::<T>() {
        Ok(val) => Ok(val),
        Err(_) => Err(std::io::Error::new(
            std::io::ErrorKind::Other,
            "Parsing failed",
        )),
    }
}
