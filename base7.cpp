//
// Created by lion on 2019/5/16.
//

//设参数为100，先用100除以49，商2余2。在除以7，商0余2，于是就得到七进制的202
string convertToBase7(int num) {
    if (num < 0) return "-" + convertToBase7(-num);
    if (num < 7) return to_string(num);
    return convertToBase7(num / 7) + to_string(num % 7);
}