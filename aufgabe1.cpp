#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;

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

void print_vec(vector<int> vec) {
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

vector<vector<int>> chips_to_signals(vector<vector<int>> chip_sequences, bool verbose) {
    vector<vector<int>> signals;
    for (int i = 0; i < chip_sequences.size(); i++) {
        replace(chip_sequences[i].begin(), chip_sequences[i].end(), 0, -1);
        if (verbose) {
            cout << "Chip sequence " << i + 1 << endl;
            print_vec(chip_sequences[i]);
        }
    }

    return signals;
}

int dot_product(vector<int> a, vector<int> b) {
    int product = 0;
    for (int i = 0; i < a.size(); ++i) {
        product += a[i] * b[i];
    }
    return product;
}

void check_sequence(vector<vector<int>> sequences, vector<int> sum_signal) {
    //Schwellwert 1023 -3*65 = 800 ca.
    for (int i = 0; i < sequences.size(); i++) {
        vector<int> sequence = sequences[i];
        for (int j = 0; j < sequence.size(); j++) {

            int product = dot_product(sequence, sum_signal);

            if (abs(product) > 400) {
                // j = Delta, i = Satellite_nr
                printf("Statellite %2d has sent bit %d (delta = %d)\n", i+1, product>0, j);
				break;
            }

            rotate(sequence.begin(), sequence.end() - 1, sequence.end());

        }
    }
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 100; ++i) {
    int n_satellites = 24;
    int chip_sequence_length = 1023;
    vector<vector<int>> chip_sequences = get_chip_sequences(n_satellites, chip_sequence_length, false);

    vector<vector<int>> signals = chips_to_signals(chip_sequences, false);

    if (argc == 2) {
        string filename = argv[1];
        vector<int> sum_signal = read_signal(filename, false);

        check_sequence(chip_sequences, sum_signal);

    }
	}
}
