pub fn vec_to_string<T: std::fmt::Display>(v: Vec<T>) -> String {
    v.iter()
        .map(|i| i.to_string())
        .collect::<Vec<String>>()
        .join(" ")
}
