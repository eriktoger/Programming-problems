use std::io::{BufRead, Error, Write};

pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;

    let lines = lines.trim().parse::<usize>().unwrap();

    for _ in 0..lines {
        let mut line = String::new();
        reader.read_line(&mut line)?;
        let numbers: Vec<&str> = line.split(" ").collect();

        let n = numbers[0].trim().parse::<usize>().unwrap();
        let k = numbers[1].trim().parse::<usize>().unwrap();
        // answer = (answer / n) + k
        // -1 is to round down
        let answer = (n * k - 1) / (n - 1);
        writeln!(writer, "{}", answer)?;
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_example() {
        let input = "6\n3 7\n4 12\n2 1000000000\n7 97\n1000000000 1000000000\n2 1\n";
        let expected_output = "10\n15\n1999999999\n113\n1000000001\n1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
