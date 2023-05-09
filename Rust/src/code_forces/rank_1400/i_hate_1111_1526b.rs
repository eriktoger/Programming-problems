use crate::common::read_line;
use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let lines: usize = read_line(reader)?;
    let mut print_line = |s: &str| writeln!(writer, "{s}");

    for _ in 0..lines {
        let x: usize = read_line(reader)?;
        let rest = x % 11;
        // the idea is to that we can exchange 111 for 11*10 and thus
        // remove 1. And we need to be able to do so for rest nr of times.
        if rest == 0 || (x >= rest * 111) {
            print_line("YES")?;
        } else {
            print_line("NO")?;
        }
    }

    Ok(())
}

#[cfg(test)]
mod tests_1526b {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_3_cases() {
        let input = "3\n33\n144\n69\n";
        let expected_output = "YES\nYES\nNO\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
