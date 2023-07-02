#include "Huffman.h"

Huffman::Huffman()
{
    extension ="HUF";
    root = nullptr;
}

Huffman::~Huffman()
{
    //dtor
}

void Huffman::buildEncodings(Node *node, std::string code)
{
    std::cout<<"Punkt kontrolny buildEncodings()";
    if (node == nullptr)
    {
        return;
    }

    if(node->left==nullptr && node->right==nullptr)
        encodings[node->character] = code;

    buildEncodings(node->left, code + "0");
    buildEncodings(node->right, code + "1");
}

Huffman::Node* Huffman::buildTree(std::vector<Node*> &nodes)
{

    auto comparator =[](const Node *a, const Node *b)
    {
        return a->frequency > b->frequency;
    };
    std::cout<<"Punkt kontrolny buildTree(nodes)1 ";
    std::priority_queue<Node*, std::vector<Node*>, decltype(comparator) > nodeQueue(comparator, nodes);
    while (nodeQueue.size() > 1)
    {
        Node *left = nodeQueue.top();
        nodeQueue.pop();
        Node *right = nodeQueue.top();
        nodeQueue.pop();
        Node *parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        nodeQueue.push(parent);
    }
    std::cout<<"Punkt kontrolny buildTree(nodes) 2";
    return nodeQueue.top();
}

void Huffman::destroyTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

void Huffman::buildFrequencyTable(char* text, int size)
{
    for(int i=0;i<size;i++)
    {
        frequencyTable[text[i]]++;
    }
}

void Huffman::buildTree()
{
    std::vector<Node*> nodes;
    for (const auto &pair: frequencyTable)
    {
        nodes.push_back(new Node(pair.first, pair.second));
    }
    std::cout<<"Punkt kontrolny buildTree()";
    root = buildTree(nodes);
    buildEncodings(root, "");
}

std::string Huffman::encode(char* text, int size)
{
    std::string encoded_text;
    for (int i=0;i<size;i++)
    {
        encoded_text += encodings[text[i]];
    }
    return encoded_text;
}

std::string Huffman::decode(std::string &text)
{
    std::string decoded_text;
    Node *current = root;
    for (char &c: text)
    {
        current = (c == '0') ? current->left : current->right;
        if(current->left==nullptr && current->right==nullptr)
        {
            decoded_text += current->character;
            current = root;
        }
    }
    return decoded_text;
}

void Huffman::saveHuffmanTree(Node* tmpRoot, std::ofstream& fileName) {
    if (tmpRoot == nullptr) {
        return;
    }
    if (tmpRoot->left == nullptr && tmpRoot->right == nullptr) {
        fileName.put('1');
        fileName.write(&tmpRoot->character,1);
    } else {
        fileName.put('0');
        saveHuffmanTree(tmpRoot->left, fileName);
        saveHuffmanTree(tmpRoot->right, fileName);
    }
}

Huffman::Node* Huffman::readHuffmanTreeFromFile(std::ifstream& fileName) {
    char type;
    fileName.read(&type, 1);

    if (type == '1') {
        char data;
        fileName.read(&data,1);
        return new Node(data, 0);
    } else if (type == '0') {
        Node* left = readHuffmanTreeFromFile(fileName);
        Node* right = readHuffmanTreeFromFile(fileName);
        Node* internal = new Node('\0', 0);
        internal->left = left;
        internal->right = right;
        return internal;
    }
}


void Huffman::compressFile(std::string fileName)
{
    std::ifstream input;
    std::ofstream output;
    input.open(fileName, std::ios::binary);
    char buffer[1024*1024];
    std::string tmp;
    while (!input.eof())
    {
        std::cout<<"dsa"<<std::endl;
        input.read(buffer,sizeof(buffer));
        buildFrequencyTable(buffer,input.gcount());
    }
    buildTree();
    std::cout<<"punkt kontrolny"<<std::endl;
    input.close();
    input.open(fileName,std::ios::binary);
    output.open(fileName+'.'+extension, std::ios::binary);
    saveHuffmanTree(root,output);
    while (!input.eof())
    {
        std::cout<<"bsaa"<<std::endl;
        input.read(buffer,sizeof(buffer));
        writeBits(output,encode(buffer,input.gcount()));
    }
    output.close();
    input.close();
    frequencyTable.clear();
    encodings.clear();
    destroyTree(root);
}

void Huffman::decompressFile(std::string fileName)
{
    std::string tmp;
    if (fileName.substr(fileName.find_last_of(".") + 1) != extension)
    {
        std::cout << "Niepoprawny rodzaj pliku!" << std::endl;
        std::cout<<fileName.substr(fileName.find_last_of(".") + 1)<<std::endl;
    }
    else
    {
        std::ofstream output(fileName.substr(0, fileName.length() - extension.length()), std::ios::binary);
        std::ifstream file(fileName, std::ios::binary);
        root=readHuffmanTreeFromFile(file);
        if (output.is_open())
        {
            while(!file.eof())
            {
                tmp = readBitsFromFile(file,1024*1024);
                output<<decode(tmp);
            }
        }
        output.close();
        file.close();
        destroyTree(root);

    }
}

