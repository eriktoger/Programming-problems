// cargo run 1700 number_of_ways 466c
use crate::common::{get_vec, read_line};
use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let len: usize = read_line(reader)?;
    let numbers: Vec<i64> = get_vec(reader)?;

    let sum: i64 = numbers.iter().sum();
    if sum % 3 != 0 {
        writeln!(writer, "0")?;
        return Ok(());
    }

    let first_seam = sum / 3;
    let mut first_seam_candidates = vec![];
    let second_seam = first_seam * 2;
    let mut second_seam_candidates = vec![];
    let mut running_sum = 0;

    for (index, number) in numbers.iter().enumerate() {
        running_sum += number;
        if running_sum == first_seam {
            first_seam_candidates.push(index);
        }
        if index != len - 1 && running_sum == second_seam {
            second_seam_candidates.push(index);
        }
    }

    if first_seam_candidates.len() == 0 || second_seam_candidates.len() == 0 {
        writeln!(writer, "0")?;
        return Ok(());
    }

    let mut answer = 0;
    let mut first_index: usize = 0;
    let mut second_index: usize = 0;
    loop {
        let current_first = first_seam_candidates[first_index];
        let current_second = second_seam_candidates[second_index];

        if current_first < current_second {
            answer += second_seam_candidates.len() - second_index;
            first_index += 1;
        } else {
            second_index += 1;
        }

        if first_index >= first_seam_candidates.len()
            || second_index >= second_seam_candidates.len()
        {
            break;
        }
    }

    writeln!(writer, "{answer}")?;

    Ok(())
}

#[cfg(test)]
mod tests_466c {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_case_1() {
        let input = "5\n1 2 3 0 3\n";
        let expected_output = "2\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_case_2() {
        let input = "4\n0 1 -1 0\n";
        let expected_output = "1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_case_3() {
        let input = "2\n4 1\n";
        let expected_output = "0\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_case_4() {
        let input = "9\n0 0 0 0 0 0 0 0 0\n";
        let expected_output = "28\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
    #[test]
    fn test_case_5() {
        let input = "10\n2 5 -2 2 -3 -2 3 5 -5 -2\n";
        let expected_output = "0\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
    #[test]
    fn test_case_11() {
        let input = "6\n1000000000 1000000000 1000000000 1000000000 1000000000 1000000000\n";
        let expected_output = "1\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
