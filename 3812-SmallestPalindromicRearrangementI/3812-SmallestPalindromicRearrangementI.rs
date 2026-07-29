// Last updated: 7/29/2026, 11:39:16 AM
impl Solution {
    pub fn smallest_palindrome(s: String) -> String {
        let mut count = [0; 26];
        for b in s.bytes() {
            count[(b - b'a') as usize] += 1;
        }

        let mut half = String::new();
        let mut mid = String::new();

        for i in 0..26 {
            let ch = (b'a' + i as u8) as char;
            let freq = count[i];
            
            // Put half of the occurrences in the first half
            for _ in 0..(freq / 2) {
                half.push(ch);
            }
            
            // If the frequency is odd, save the character for the middle
            if freq % 2 == 1 {
                mid.push(ch);
            }
        }

        let rev: String = half.chars().rev().collect();
        format!("{}{}{}", half, mid, rev)
    }
}