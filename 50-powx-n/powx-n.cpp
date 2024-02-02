// class Solution {
// public:
//     double f1(double x, int n, double& o) {
//         if (n > 0) {
//             if (x >= 1 || x <= -1)
//                 o = x * o;
//             else {
//                 if (o > pow(10, -15)) {
//                     o = x * o;

//                 } else {
//                     return 0;
//                 }
//             }

//         } else {
//             return o;
//         }
//         f1(x, n - 1, o);
//         return o;
//     }
//     double f2(double x, int n, double& o) {
//         if (n < 0) {
//             if (o > pow(10, -15)) {
//                 o = (1 / x) * o;

//             } else {
//                 return 0;
//             }
//         } else {
//             return o;
//         }
//         f2(x, n + 1, o);
//         return o;
//     }
//     double myPow(double x, int n) {
//         double o = 1;
//         if (n > 0) {
//             o = f1(x, n, o);
//         } else {
//             o = f2(x, n, o);
//         }

//         return o;
//     }
// };
class Solution {
public:
    double myPow(double x, int n) {
		double s = 1;
		s = pow(x, n);
        return s ;
    }
};