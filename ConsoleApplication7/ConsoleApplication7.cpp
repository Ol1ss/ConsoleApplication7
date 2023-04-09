#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileWorker {
private:
    static FileWorker* instance;
    FileWorker() {}
public:
    static FileWorker* getInstance() {
        if (instance == NULL) {
            instance = new FileWorker();
        }
        return instance;
    }
    void createFile(string path) {
        ofstream file(path);
        if (file) {
            cout << "File created successfully!" << endl;
            file.close();
        }
        else {
            cout << "Error creating file." << endl;
        }
    }
    void renameFile(string oldPath, string newPath) {
        if (rename(oldPath.c_str(), newPath.c_str()) != 0) {
            cout << "Error renaming file." << endl;
        }
        else {
            cout << "File renamed successfully!" << endl;
        }
    }
    void deleteFile(string path) {
        if (remove(path.c_str()) != 0) {
            cout << "Error deleting file." << endl;
        }
        else {
            cout << "File deleted successfully!" << endl;
        }
    }
    bool fileExists(string path) {
        ifstream file(path);
        if (file) {
            file.close();
            return true;
        }
        else {
            return false;
        }
    }
};

FileWorker* FileWorker::instance = NULL;

int main() {
    FileWorker* fileWorker = FileWorker::getInstance();

    fileWorker->createFile("test.txt");
    fileWorker->renameFile("test.txt", "newtest.txt");
    fileWorker->deleteFile("newtest.txt");
    cout << "File exists? " << fileWorker->fileExists("newtest.txt") << endl;

    return 0;
}