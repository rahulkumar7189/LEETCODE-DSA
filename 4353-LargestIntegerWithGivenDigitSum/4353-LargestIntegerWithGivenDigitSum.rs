// Last updated: 7/29/2026, 11:38:50 AM
impl Solution {
    pub fn largest_integer(n: i32, s: i32) -> i32 {
        if s > 9*n {
            return -1;
        }

        let mut ans =0;
        let mut sum=s;
        let mut digits = n;
        while digits>0{
            let d =sum.min(9);
            ans=ans*10+d;
            sum-=d;
            digits-=1;
            
        }
        ans
    }
}