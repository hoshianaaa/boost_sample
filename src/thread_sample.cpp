// 引用: https://www.mathkuro.com/c-cpp/boost/how-to-use-boost-thread/

#include <iostream>
#include <boost/thread.hpp>

#define LOOP_NUM 5

// hogehogeと標準出力する関数
void Hoge() {
  for(int i = 0; i != LOOP_NUM; i++) {
    // hogehogeと標準出力(標準出力はスレッドセーフじゃないから本当は排他制御が必要だけど今回は省略)
    std::cout << "hogehoge" << std::endl;

    // 100ミリ秒スリープ
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
}

// piyopiyoと標準出力する関数
void Piyo() {
  for(int i = 0; i != LOOP_NUM; i++) {
    // piyopiyoと標準出力(標準出力はスレッドセーフじゃないから本当は排他制御が必要だけど今回は省略)
    std::cout << "piyopiyo" << std::endl;

    // 100ミリ秒スリープ
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
}

// main
int main() {
  // Hogeスレッドの生成と実行(&は無くてもよい)
  boost::thread th_hoge(&Hoge);

  // Piyoスレッドの生成と実行(&は無くてもよい)
  boost::thread th_piyo(&Piyo);

  // スレッドの終了を待つ(逆順でも問題ない)
  th_hoge.join();
  th_piyo.join();

  return 0;
}
