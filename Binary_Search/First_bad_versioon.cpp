/*yeh quetion search space ka h or isme ek API based function define kiya gya h jo sirf api request krne pe is run ho to 
maine sirf main fuction likh diya as per leetcode*/

// int firstBadVersion(int n) {
//         // search space ka questin hai
//         int s = 1;
//         int e = n;
//         while (s < e) {
//             int mid = s + (e - s) / 2;
//             if (isBadVersion(mid)) {  //^isBadVersion predefine function based on api
//                 e = mid;
//             } else {
//                 s = mid + 1;
//             }
//         }
//         return e;
// }