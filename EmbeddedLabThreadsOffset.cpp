#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <thread>

using namespace std;

#define CHIP_SEQUENCE_LENGTH 1023
#define N_SATELLITES 24

vector<int> given_signal = { -2,0,-2,-2,0,-2,-2,2,0,2,-2,-2,-4,-2,2,0,4,0,0,-2,0,2,0,2,2,2,4,0,-4,-2,0,-2,2,2,2,0,0,-2,2,2,0,0,0,0,2,2,-2,2,-2,-2,-2,-4,-2,0,-4,0,-2,2,-4,4,-4,0,0,2,0,2,2,0,0,2,0,-2,2,-4,-4,2,2,4,0,-2,0,2,0,-4,-2,0,2,2,0,-4,0,-2,0,2,0,2,-2,-2,2,-2,2,-2,4,4,0,-2,0,0,2,-2,-2,0,2,4,0,0,-2,-2,0,4,-2,2,2,0,2,-2,-2,0,0,2,-2,-2,0,-2,0,0,0,2,2,-2,-2,2,2,-2,-2,-2,0,-4,4,0,0,2,0,0,-2,0,-2,-2,0,4,2,0,0,0,-4,-2,-2,0,0,0,-4,-4,2,0,2,2,0,-2,-4,-4,0,0,0,0,2,2,4,0,-2,0,2,-2,-2,2,0,0,2,-2,0,0,-2,2,-2,2,2,2,-2,0,0,0,4,2,0,-4,0,-4,0,4,2,-2,0,0,-4,-2,2,0,0,2,0,-2,-2,0,0,2,0,0,0,0,0,-2,2,-2,0,-2,0,2,0,2,2,0,-2,0,2,0,2,0,-2,0,-4,-2,0,2,-2,0,-4,-4,2,0,2,2,-2,0,0,4,2,-4,-4,-2,-4,0,-4,0,-2,-2,0,0,4,0,-4,2,0,2,0,-2,0,-2,-2,0,4,-2,4,0,0,-2,0,-2,0,0,-2,0,-2,2,0,0,0,-2,2,2,-4,0,0,-2,0,2,0,-4,-2,0,0,0,-2,-2,0,-4,2,2,2,2,2,0,0,2,-4,2,2,-2,-2,0,2,0,0,-2,2,-2,0,0,-2,-4,0,2,4,2,-2,4,2,2,2,-2,0,0,-4,-2,2,2,0,0,0,-2,2,-2,0,-4,4,0,0,-2,0,-2,2,2,0,-2,-4,-4,2,-4,-2,2,-2,0,2,-2,2,2,2,4,0,-2,0,2,0,2,0,2,0,0,0,-2,0,0,0,-2,0,2,-2,2,0,2,0,-2,-2,2,4,2,-2,-4,-2,0,-2,-2,2,0,-4,0,0,0,0,0,0,0,2,0,2,2,-2,2,-2,2,-2,2,-2,-2,0,2,0,-2,-2,-4,2,2,2,-4,2,-2,2,-2,0,2,0,4,0,0,-2,-2,0,2,-2,2,-4,2,0,2,2,0,-2,4,2,-2,0,2,-4,0,-2,2,4,-4,2,-2,4,0,0,-2,2,-2,4,4,0,-2,2,-2,0,-2,0,0,0,0,2,0,0,-2,-4,0,0,-2,4,4,2,-2,2,0,0,0,2,-4,2,0,0,0,2,-2,-2,-2,-2,0,2,2,-2,0,2,4,-2,0,-4,2,0,-2,-2,0,0,-2,0,-4,-4,0,4,2,-2,2,0,0,0,-4,0,-4,0,2,2,4,0,0,0,-2,0,-2,0,2,2,0,-2,0,2,0,0,0,2,-4,-2,2,-2,-4,2,0,0,4,-2,0,0,-2,2,-2,0,2,2,2,4,0,2,-2,0,-2,2,0,2,0,2,2,4,-2,0,0,0,-2,0,0,0,0,-4,-2,2,2,2,0,0,2,0,-4,2,-4,2,-2,0,0,-2,2,0,0,-2,-2,0,0,0,0,0,-2,-2,-2,0,-2,0,2,2,-2,2,-2,2,2,0,2,0,2,-2,0,2,-2,0,0,0,4,-2,2,0,0,-4,-2,-2,2,2,2,0,-2,2,4,0,-2,2,0,0,-2,-4,-2,2,0,2,-2,-2,2,-2,4,-2,-2,2,0,2,2,0,4,2,0,-2,-2,2,0,0,0,0,2,2,-4,-2,2,-4,0,0,-4,-2,-2,-2,0,-2,2,-2,-4,0,4,0,0,2,2,-2,0,0,0,0,0,0,-2,2,-2,0,2,-2,-2,0,4,2,2,-2,0,2,2,0,-2,4,0,2,0,0,0,2,2,-4,0,-2,0,2,2,2,2,0,0,0,-2,4,-2,0,-2,0,2,0,4,0,0,0,2,-2,0,-2,-2,4,2,0,2,0,-2,-2,0,0,0,-2,4,0,-2,0,-4,0,2,2,-2,2,2,-2,2,0,0,-2,-2,0,0,0,2,0,2,0,2,-2,2,4,2,2,2,2,-2,0,0,2,4,-2,0,-2,2,2,2,0,-2,0,-2,4,0,0,-4,4,0,0,-2,-2,0,0,0,2,4,0,2,2,2,0,0,-2,-4,-2,4,4,0,0,2,2,4,4,0,0,-2,-2,0,0,0,-2,4,0,2,2,4,0,-2,-2,2,-2,2,2,0,0,4,-2,-2,-2,0,-4,0,2,0,2,0,-4,2,4,-2,2,0,0,-2,4,-2,4,-2,0,-4,-2,0,2,0,-4,-2,0,2,2,2,-2,-2,0,0,2,-2,2,0,0,-2,2,4,2,0,0,0,-2,4,0,0,0,-2,2,-2,0,-2,0,2,-2,-2,0,0,2,0,2,-2,2,-2,0,0,0,0,-2,-4,2,-4,2,0,0 };

vector<int> generate_chip_seq(int first_reg, int second_reg, int chip_sequence_length) {
    vector<int> chip_seq;
    vector<int> registers_top(10, 1);
    vector<int> registers_bottom(10, 1);
    for (int i = 0; i < chip_sequence_length; i++) {
        int top_xor = registers_top[2] ^ registers_top[9];
        int previous_last_top = registers_top[9];
        registers_top[9] = top_xor;
        rotate(registers_top.begin(), registers_top.end() - 1, registers_top.end());
        int middle_xor_left = registers_bottom[first_reg - 1] ^ registers_bottom[second_reg - 1];
        chip_seq.push_back(previous_last_top ^ middle_xor_left);
        int bottom_xor = registers_bottom[1] ^ registers_bottom[2] ^ registers_bottom[5] ^ registers_bottom[7] ^ registers_bottom[8] ^ registers_bottom[9];
        registers_bottom[9] = bottom_xor;
        rotate(registers_bottom.begin(), registers_bottom.end() - 1, registers_bottom.end());
    }
    return chip_seq;
}

vector<int> read_signal(string filename, bool verbose) {
    vector<int> sum_signal;

    ifstream signal_file;
    signal_file.open(filename);
    int temp;
    if (verbose) {
        cout << "Sum signal:" << endl;
    }

    while (signal_file >> temp) {
        sum_signal.push_back(temp);
        if (verbose) {
            cout << temp << " ";
        }

    }
    if (verbose) {
        cout << endl;
    }
    signal_file.close();
    return sum_signal;
}

void print_vec(vector<int>& vec) {
    stringstream result;
    copy(vec.begin(), vec.end(), ostream_iterator<int>(result, " "));
    cout << result.str() << endl << endl;
}

vector<vector<int>> get_chip_sequences(int n_satellites, int chip_sequence_length, bool verbose) {
    vector<vector<int>> sequences;
    vector<int> first_regs{ 2,3,4,5,1,2,1,2,3,2,3,5,6,7,8,9,1,2,3,4,5,6,1,4 };
    vector<int> second_regs{ 6,7,8,9,9,10,8,9,10,3,4,6,7,8,9,10,4,5,6,7,8,9,3,6 };

    for (int i = 0; i < n_satellites; i++) {
        sequences.push_back(generate_chip_seq(first_regs[i], second_regs[i], chip_sequence_length));

        if (verbose) {
            cout << "Chip sequence of satellite " << i + 1 << ": " << endl;
            print_vec(sequences[i]);
        }
    }
    return sequences;
}

vector<vector<int>> chips_to_signals(vector<vector<int>>& chip_sequences, bool verbose) {
    vector<vector<int>> signals;
    for (unsigned int i = 0; i < chip_sequences.size(); i++) {
        replace(chip_sequences[i].begin(), chip_sequences[i].end(), 0, -1);
        if (verbose) {
            cout << "Chip sequence " << i + 1 << endl;
            print_vec(chip_sequences[i]);
        }
    }

    return signals;
}

int dot_product(const vector<int>& a, const vector<int>& b, unsigned int delta, float factor) {
    int product = 0;
    for (unsigned int i = 0; i < a.size()*factor; ++i) {
        product += a[i] * b[(i + delta) % b.size()];
    }
    return product;
//
    size_t thresh = a.size() * factor;
    size_t wrap = min(a.size() - delta, thresh);

    size_t i = 0;
    for (; i < wrap; ++i) {
        product += a[i] * b[i + delta];
    }
    // early stop. wir wollen nur wissen, ob wir thresh überschreiten
    if (abs(product) > thresh) {
        return product;
    }

    // falls wrap < thresh: continue
    for (; i < thresh; ++i) {
        product += a[i] * b[i + delta - a.size()];
    }

    return product;
}

void check_sequence(const vector<vector<int>>& sequences, const vector<int>& sum_signal, int idx) {
    // Schwellwert 1023 -3*65 = 828
    float factor = 0.5f;
    vector<int> sequence = sequences[idx];
    for (unsigned int delta = 0; delta < sequence.size(); delta++) {
        int product = dot_product(sequence, sum_signal, delta, factor);

        if (abs(product) > 828 * factor) {
            printf("Statellite %2d has sent bit %d (delta = %d)\n", idx + 1, product > 0, delta);
            cout << "";
            break;
        }

        // rotate(sequence.begin(), sequence.end() - 1, sequence.end());
    }
}

void check_sequences(vector<vector<int>>& sequences, const vector<int>& sum_signal) {
    const int processor_count = std::thread::hardware_concurrency();
    int to_check = N_SATELLITES;
    while (to_check > 0) {
        std::vector<thread> threads(min((int)processor_count, to_check));
        for (int i = 0; i < threads.size(); i++) {
            threads[i] = thread([sequences, sum_signal, i, to_check] {check_sequence(sequences, sum_signal, i + (N_SATELLITES - to_check)); });
        }
        for (int i = 0; i < threads.size(); ++i) {
            threads[i].join();
            to_check--;
        }
    }
}

vector<double> run(int argc, char* argv[], vector<double> sums) {
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;
    int n_satellites = 24;
    int chip_sequence_length = 1023;
    string filename;
    if (argc == 2) {
        filename = argv[1];
    }
    else {
        filename = "gps_sequence_3.txt";
    }

    auto t1 = high_resolution_clock::now();
    vector<vector<int>> chip_sequences = get_chip_sequences(n_satellites, chip_sequence_length, false);
    auto t2 = high_resolution_clock::now();
    vector<vector<int>> signals = chips_to_signals(chip_sequences, false);
    auto t3 = high_resolution_clock::now();
    vector<int> sum_signal = read_signal(filename, false);
    auto t4 = high_resolution_clock::now();
    check_sequences(chip_sequences, sum_signal);
    auto t5 = high_resolution_clock::now();

    duration<double, std::milli> f4 = t5 - t4;
    duration<double, std::milli> f3 = t4 - t3;
    duration<double, std::milli> f2 = t3 - t2;
    duration<double, std::milli> f1 = t2 - t1;
    duration<double, std::milli> f5 = t5 - t1;

    //std::cout << ms_int.count() << "ms\n";
    //std::cout << ms_double.count() << "ms\n";
    //printf("%f,%f,%f,%f\n", t5 - t4, t4 - t3, t3 - t2, t2 - t1);
    //cout << f1.count() << "," << f2.count() << "," << f3.count() << "," << f4.count() << endl;
    sums[0] += f1.count();
    sums[1] += f2.count();
    sums[2] += f3.count();
    sums[3] += f4.count();
    sums[4] += f5.count();

    return sums;
}

int main(int argc, char* argv[]) {
    int n_runs = 100;
    
    vector<double> sums(5, 0);
    // cout << setprecision(6);
    for (int i = 0; i < n_runs; i++) {
        sums = run(argc, argv, sums);
    }
    const int processor_count = std::thread::hardware_concurrency();
    cout << "\nThreads used: " << processor_count << endl;
    cout << "\n\nn_runs = " << n_runs << "\tget_chip_sequences\tchips_to_signals\tread_signal\t\tcheck_sequences\t\tTotal" << endl;
    cout << "Total:\t\t";
    for (auto i : sums)
        cout << i << "ms\t\t";
    cout << endl << "Average:\t";
    for (auto i : sums)
        cout << i / n_runs << "ms\t\t";
    cout << endl;
}
