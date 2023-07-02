#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <Compressor.h>


class Huffman : public Compressor
{
    public:
        Huffman();
        virtual ~Huffman();
        void buildFrequencyTable(char* text, int size);
        void buildTree();
        void compressFile(std::string fileName);
        void decompressFile(std::string fileName);
        std::string encode(char *text, int size) override;
        std::string decode(std::string &text) override;



    protected:

    private:

        struct Node
		{
			char character;
			int frequency;
			Node * left;
			Node * right;
			Node(char character, int frequency): character(character), frequency(frequency), left(nullptr), right(nullptr) {}
		};
		Node * root;
        std::map<char, std::string > encodings;
        std::map<char, int> frequencyTable;
    	void buildEncodings(Node *node, std::string code);
        Node* buildTree(std::vector<Node*> &nodes);
        void saveHuffmanTree(Node* tmpRoot, std::ofstream& fileName);
        Node* readHuffmanTreeFromFile(std::ifstream& fileName);
        void destroyTree(Node* root);
        int numberOfChunks=0;
        std::string convertToString(char* a, int size);

};

#endif // HUFFMAN_H
