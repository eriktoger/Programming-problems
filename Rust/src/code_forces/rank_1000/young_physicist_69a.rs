use std::io::{BufRead, Error, Write};

pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;

    let lines = lines.trim().parse::<usize>().unwrap();
    let mut sums = [0, 0, 0];
    for _ in 0..lines {
        let mut line = String::new();
        reader.read_line(&mut line)?;
        let numbers = line.split(" ");
        for (i, number) in numbers.enumerate() {
            sums[i] += number.trim().parse::<i32>().unwrap()
        }
    }

    match sums.iter().find(|number| **number != 0) {
        Some(_) => writeln!(writer, "NO"),
        None => writeln!(writer, "YES"),
    }?;

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_no() {
        let input = "3\n4 1 7\n-2 4 -1\n1 -5 -3\n";
        let expected_output = "NO\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(output, expected_output.as_bytes());
    }

    #[test]
    fn test_get_solution_yes() {
        let input = "3\n3 -1 7\n-5 2 -4\n2 -1 -3\n";
        let expected_output = "YES\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(output, expected_output.as_bytes());
    }
}
