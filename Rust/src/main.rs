mod code_forces;
use code_forces::rank_1200::kth_not_divisible_by_n_1352c::get_solution;

fn main() {
    let stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let _ = get_solution(&mut stdin.lock(), &mut stdout);
    std::io::Write::flush(&mut stdout).unwrap();
}
