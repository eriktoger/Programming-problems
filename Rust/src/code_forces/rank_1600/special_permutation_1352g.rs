use crate::common::{read_line, vec_to_string};
use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let test_cases: usize = read_line(reader)?;

    for _ in 0..test_cases {
        let n: usize = read_line(reader)?;

        if n == 1 {
            writeln!(writer, "1")?;
            continue;
        }

        if n == 2 || n == 3 {
            writeln!(writer, "-1")?;
            continue;
        }

        let mut numbers = vec![];

        let mut current = n;

        while current > 4 {
            numbers.push(current);
            current -= 2;
        }
        numbers.extend(&[3, 1, 4, 2]);

        current = if n % 2 == 0 { 5 } else { 6 };

        while current < n {
            numbers.push(current);
            current += 2;
        }

        let answer = vec_to_string(numbers);
        writeln!(writer, "{answer}")?;
    }

    Ok(())
}

#[cfg(test)]
mod tests_1352g {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_3_cases() {
        let input = "6\n\
                     10\n\
                     2\n\
                     4\n\
                     6\n\
                     7\n\
                     13\n";
        let expected_output = "10 8 6 3 1 4 2 5 7 9\n\
                               -1\n\
                               3 1 4 2\n\
                               6 3 1 4 2 5\n\
                               7 5 3 1 4 2 6\n\
                               13 11 9 7 5 3 1 4 2 6 8 10 12\n";

        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        let actual_output = std::str::from_utf8(&output).unwrap();
        assert_eq!(actual_output, expected_output);
    }
}
