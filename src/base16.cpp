#include <string>
#include <vector>

using namespace std;

static const string base16_enc_chars = "0123456789ABCDEF";

string base16_encode(const vector<uint8_t>& data) {
	string result;
	for (int i = 0; i < data.size(); i++) {
		unsigned char h = data[i] >> 4;
		unsigned char l = data[i] & 0x0F;
		result.push_back(base16_enc_chars[h]);
		result.push_back(base16_enc_chars[l]);
	}
	return result;
}

static const vector<char> base16_dec_chars{
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	-1, -1, -1, -1, -1, -1, -1,
	10, 11, 12, 13, 14, 15
};

vector<uint8_t> base16_decode(const string& data) {
	vector<uint8_t> result;
	for (int i = 0; i < data.size(); i+=2) {
		unsigned char h = base16_dec_chars[data[i]];
		unsigned char l = base16_dec_chars[data[i + 1]];

		result.push_back((h << 4) | l);
	}
	return result;
}

/**
int main()
{
	string teststr{ "这是测试用的 base16 for test!!!" };
	vector<uint8_t> test_vector = vector<uint8_t>(teststr.begin(), teststr.end());
	string encode_data = base16_encode(test_vector);
	cout << "Encoded data: " << test_vector.data() << " Encode Result: " << encode_data << endl;

	vector<uint8_t> decode_data = base16_decode(encode_data);
	cout << "Encoded data: " << test_vector.data() << " Decode Result: " << decode_data.data() << endl;
	return 0;
}
*/