use crate::common::read_line;
use std::io::{BufRead, Error, Write};

fn get_moves(s: &str, c: char) -> usize {
    if c == '{' {
        return 131073;
    }

    let len = s.len();
    if len == 1 && s == c.to_string() {
        return 0;
    }
    if len == 1 {
        return 1;
    }

    let mid = len / 2;
    let left = &s[0..mid];
    let right = &s[mid..];

    let left_count = left.chars().filter(|&lc| lc == c).count();
    let right_count = right.chars().filter(|&lc| lc == c).count();

    let next_char = unsafe { std::char::from_u32_unchecked(c as u32 + 1) };

    return std::cmp::min(
        mid - left_count + get_moves(right, next_char),
        mid - right_count + get_moves(left, next_char),
    );
}

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let test_cases: usize = read_line(reader)?;

    for _ in 0..test_cases {
        let _: usize = read_line(reader)?;
        let good_string: String = read_line(reader)?;

        let moves = get_moves(&good_string, 'a');
        writeln!(writer, "{moves}")?;
    }
    Ok(())
}

#[cfg(test)]
mod tests_1385d {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_3_cases() {
        let input = "6\n8\nbbdcaaaa\n8\nasdfghjk\n8\nceaaaabb\n8\nbbaaddcc\n1\nz\n2\nac\n";
        let expected_output = "0\n7\n4\n5\n1\n1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_2_370_cases() {
        let input = "1\n16\ndezlyajbqcuowzvc\n";
        let expected_output = "13\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_2_371_cases() {
        let input = "1\n16\nojkrrxasyxpefhxn\n";
        let expected_output = "14\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
