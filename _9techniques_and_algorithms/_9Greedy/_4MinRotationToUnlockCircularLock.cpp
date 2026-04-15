// rotete and unlock er position deoya thkbe..min koibar rotate krle unlock hbe..0,1,2 clock wise..0,9,8 anti clock wise.
// int rotationCount(long long R, long long D)
// {
//     int ans = 0;

//     while (R)
//     {
//         int first = R % 10;
//         int second = D % 10;
//         R /= 10;
//         D /= 10;

//         ans += min(abs(first - second), 10 - abs(first - second)); // clock wise then anti clock wise
//     }

//     return ans;
// }