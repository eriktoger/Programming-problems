use std::io::{self, Error};

pub fn get_solution() -> Result<(), Error> {
    let mut lines = String::new();

    io::stdin().read_line(&mut lines)?;

    let lines = lines.trim().parse::<usize>().unwrap();
    let mut sums = [0, 0, 0];
    for _ in 0..lines {
        let mut line = String::new();
        io::stdin().read_line(&mut line)?;
        let numbers = line.split(" ");
        for (i, number) in numbers.enumerate() {
            sums[i] += number.trim().parse::<i32>().unwrap()
        }
    }

    match sums.iter().find(|number| **number != 0) {
        Some(_) => println!("NO"),
        None => println!("YES"),
    }

    Ok(())
}
