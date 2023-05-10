use crate::common::{find_first_positive_index, get_vec, read_line};
use std::io::{BufRead, Error, Write};

#[allow(dead_code)]
pub fn get_solution<R: BufRead, W: Write>(reader: &mut R, writer: &mut W) -> Result<(), Error> {
    let length = read_line::<R, String>(reader)?
        .trim()
        .parse::<usize>()
        .unwrap();

    let a: Vec<i32> = get_vec(reader)?;
    let b: Vec<i32> = get_vec(reader)?;
    let mut diff: Vec<i32> = (0..a.len()).map(|i| a[i] - b[i]).collect();
    diff.sort();

    let first_positiv = find_first_positive_index(&diff);
    let combos = match first_positiv {
        Some(0) => length * (length - 1) / 2,
        Some(index) => {
            let mut pointer_low = index - 1;
            let mut pointer_high = index;
            let mut out_of_left_bound = false;
            let mut combos: usize = 0;

            while pointer_high < length {
                let out_of_bound = out_of_left_bound || pointer_high >= length;

                if !out_of_bound && diff[pointer_low] + diff[pointer_high] > 0 {
                    if pointer_low == 0 {
                        out_of_left_bound = true;
                    } else {
                        pointer_low -= 1;
                    }
                } else if !out_of_bound {
                    combos += pointer_high - pointer_low - 1;
                    pointer_high += 1;
                } else if out_of_left_bound {
                    combos += pointer_high;
                    pointer_high += 1;
                } else {
                    break;
                }
            }
            combos
        }
        None => 0,
    };

    writeln!(writer, "{combos}")?;
    Ok(())
}

#[cfg(test)]
mod tests_1324d {
    use super::*;
    use std::io::BufReader;

    #[test]
    fn test_get_solution_1() {
        let input = "5\n4 8 2 6 2\n4 5 4 1 3\n";
        let expected_output = "7\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }

    #[test]
    fn test_get_solution_2() {
        let input = "4\n1 3 2 4\n1 3 2 4\n";
        let expected_output = "0\n";
        let mut output = Vec::new();
        get_solution(&mut BufReader::new(input.as_bytes()), &mut output).unwrap();
        assert_eq!(std::str::from_utf8(&output).unwrap(), expected_output);
    }
}
