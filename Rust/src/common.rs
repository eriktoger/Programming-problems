use std::{
    fmt::Debug,
    io::{BufRead, Error, ErrorKind},
    str::FromStr,
};

pub fn read_line<R: BufRead, T: FromStr>(reader: &mut R) -> Result<T, Error> {
    let mut lines = String::new();
    reader.read_line(&mut lines)?;
    match lines.trim().parse::<T>() {
        Ok(val) => Ok(val),
        Err(_) => Err(Error::new(ErrorKind::Other, "Parsing failed")),
    }
}

pub fn get_vec<R: BufRead, T: FromStr>(reader: &mut R) -> Result<Vec<T>, Error>
where
    T: Ord,
    <T as FromStr>::Err: Debug,
{
    Ok(read_line::<R, String>(reader)?
        .split(" ")
        .map(|item| item.trim().parse::<T>().unwrap())
        .collect())
}

pub fn find_first_positive_index(arr: &[i32]) -> Option<usize> {
    if arr[0] > 0 {
        return Some(0);
    }
    let mut left = 0;
    let mut right = arr.len() - 1;
    let mut result = None;

    while left <= right {
        let mid = left + (right - left) / 2;

        if arr[mid] > 0 {
            result = Some(mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    result
}
