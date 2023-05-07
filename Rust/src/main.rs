mod code_forces;
use code_forces::rank_1000::young_physicist_69a::get_solution;
use std::io::{self, Write};

fn main() {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    let _ = get_solution(&mut stdin.lock(), &mut stdout);
    stdout.flush().unwrap();
}
