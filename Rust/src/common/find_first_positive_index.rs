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
