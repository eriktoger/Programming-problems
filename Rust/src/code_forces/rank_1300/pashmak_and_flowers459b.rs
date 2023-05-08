use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;

    let mut smallest = (usize::MAX, usize::MIN);
    let mut largest = (usize::MIN, usize::MIN);

    let mut line = String::new();

    reader.read_line(&mut line)?;
    let flowers: Vec<usize> = line
        .split(" ")
        .map(|item| item.trim().parse::<usize>().unwrap())
        .collect();

    for flower in flowers {
        if flower < smallest.0 {
            smallest = (flower, 1);
        } else if flower == smallest.0 {
            smallest.1 += 1;
        }

        if flower > largest.0 {
            largest = (flower, 1);
        } else if flower == largest.0 {
            largest.1 += 1;
        }
    }
    let diff = largest.0 - smallest.0;
    let combos = if diff == 0 {
        let n = smallest.1;
        (n - 1) * n / 2
    } else {
        smallest.1 * largest.1
    };
    writeln!(writer, "{diff} {combos}")?;

    Ok(())
}

#[cfg(test)]
mod tests_459b {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_1() {
        let input = "2\n1 2\n";
        let expected_output = "1 1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_2() {
        let input = "3\n1 4 5\n";
        let expected_output = "4 1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_3() {
        let input = "5\n3 1 2 3 1\n";
        let expected_output = "2 4\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_5() {
        let input = "2\n1 1\n";
        let expected_output = "0 11\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
