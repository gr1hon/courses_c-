#include <iostream>
#include <filesystem>

using namespace std;

auto recursiveGetFileNamesByExtension = [](const filesystem::path& path, const std::string& extension){
    for(auto& p: filesystem::recursive_directory_iterator(path)){
        if (p.is_regular_file()){
            if(!p.path().extension().compare(extension)){
                cout << p.path().filename() << endl;
            }
        }
    }
};

int main(){
    recursiveGetFileNamesByExtension("path", "extension");
}
