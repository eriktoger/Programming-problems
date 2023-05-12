use super::read_line::read_line;

pub fn get_vec<R: std::io::BufRead, T>(reader: &mut R) -> Result<Vec<T>, std::io::Error>
where
    T: Ord,
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    Ok(read_line::<R, String>(reader)?
        .split(" ")
        .map(|item| item.trim().parse::<T>().unwrap())
        .collect())
}
