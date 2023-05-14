use crate::common::{read_line, vec_to_string};
use std::{
    collections::VecDeque,
    io::{BufRead, Error, Write},
};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let test_cases: usize = read_line(reader)?;

    for _ in 0..test_cases {
        let _: usize = read_line(reader)?;
        let input: String = read_line(reader)?;

        let mut indices = vec![];
        let mut max = 0;
        let mut ones: VecDeque<usize> = VecDeque::new();
        let mut zeros: VecDeque<usize> = VecDeque::new();

        for c in input.chars() {
            let (primary, secondary) = if c == '0' {
                (&mut zeros, &mut ones)
            } else {
                (&mut ones, &mut zeros)
            };

            let counter = match primary.pop_front() {
                Some(val) => val,
                None => max + 1,
            };

            secondary.push_back(counter);
            indices.push(counter);
            max = usize::max(max, counter);
        }

        writeln!(writer, "{max}")?;

        let s = vec_to_string(indices);

        writeln!(writer, "{s}")?;
    }
    Ok(())
}

#[cfg(test)]
mod tests_1399d {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_1() {
        let input = "4\n4\n0011\n6\n111111\n5\n10101\n8\n01010000\n";
        let expected_output = "2\n1 2 1 2\n6\n1 2 3 4 5 6\n1\n1 1 1 1 1\n4\n1 1 1 1 1 2 3 4\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_35() {
        let input = "1\n5\n00100\n";
        let expected_output = "3\n1 2 1 1 3\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
