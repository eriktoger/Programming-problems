// cargo run 1500 special_elements 1352e
use crate::common::{get_vec, read_line};
use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let test_cases: usize = read_line(reader)?;

    for _ in 0..test_cases {
        let size: usize = read_line(reader)?;
        let nums: Vec<usize> = get_vec(reader)?;
        let max_num = nums.iter().max().unwrap();
        let len = *max_num + 1;
        let mut sums = vec![0; len];

        for index_1 in 0..size {
            let mut sum = nums[index_1];
            'inner: for index_2 in index_1..size {
                if index_1 == index_2 {
                    continue;
                }

                sum += nums[index_2];
                if sum > *max_num {
                    break 'inner;
                }

                sums[sum] = 1;
            }
        }

        let count = nums.iter().filter(|num| sums[**num] == 1).count();

        writeln!(writer, "{count}")?;
    }

    Ok(())
}

#[cfg(test)]
mod tests_1352e {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_1_cases() {
        let input = "5
        9
        3 1 4 1 5 9 2 6 5
        3
        1 1 2
        5
        1 1 1 1 1
        8
        8 7 6 5 4 3 2 1
        1
        1";
        let expected_output = "5\n\
        1\n\
        0\n\
        4\n\
        0\n\
        ";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_2_cases() {
        let input = "1
        12
        5 8 10 1 1 10 7 3 12 3 3 7
       ";
        let expected_output = "3\n\
        ";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
