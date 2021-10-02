use proconio::input;

fn main() {
    input! {
        n: usize,
        k: u32,
    }

    let mut soinsu_num: Vec<u32> = vec![0; n + 1];

    // 素数の倍数になっている数に+1していく
    // ↑の過程で一緒に素数が判定できる
    for now in 2..n {
        if soinsu_num[now] == 0 {
            for multiple in (now..=n).step_by(now) {
                soinsu_num[multiple] += 1;
            }
        }
    }

    let ans = soinsu_num.into_iter().filter(|&x| x >= k).count();
    println!("{}", ans);
}
