#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

int ls(string directory);
int makedir(string directory);
int deldir(string directory);
int deldirrecusive(string directory);
int createfile(string filename);
int deletefile(string filename);
int renamefile(string filename, string changefilename);
int renamefolder(string foldername, string changefoldername);
int movefolder(string foldername, string copyfoldername);
int filesize(string filename);
int fileinfo(string filename);
int filepermissions(string filename);
int copyfile(string filename, string copyfilename);

int main()
{
    int selection;

    do
    {
        cout << "  COSC Menu\n";
        cout << "  ====================================\n";
        cout << "  1.  List Contents of Directory\n";
        cout << "  2.  Make a Directory\n";
        cout << "  3.  Delete a Directory\n";
        cout << "  4.  Delete a Directory Recursivily \n";
        cout << "  5.  Create a File \n";
        cout << "  6.  Delete a File \n";
        cout << "  7.  Rename a File \n";
        cout << "  8.  Rename a Folder \n";
        cout << "  9.  Move a Folder \n";
        cout << "  10.  File Size \n";
        cout << "  11.  File Info \n";
        cout << "  12.  File Permissions \n";
        cout << "  13.  Copy File \n";

        cout << "\n";
        cout << "  X.  Exit\n";
        cout << "  ====================================\n";
        cout << "  Enter your selection: ";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
        case 1:
        {
            string directory;
            cout << "Type a directory name to see the contents.  \n";
            cin >> directory;
            ls(directory);
            break;
        }

        case 2:
        {
            string directory;
            cout << "Make Directory\n";
            cout << "Type a directory name to create.  \n";
            cin >> directory;
            makedir(directory);
            break;
        }

        case 3:
        {
            string directory;
            cout << "Delete Directory\n";
            cout << "Type a directory name delete it.  \n";
            cin >> directory;
            deldir(directory);
            break;
        }

        case 4:
        {
            string directory;
            cout << "Delete Directory\n";
            cout << "Type a directory name delete it.  \n";
            cin >> directory;
            deldirrecusive(directory);
            break;
        }

        case 5:
        {
            string filename;
            cout << "Create a file\n";
            cout << "Type a file name to create it.  \n";
            cin >> filename;
            createfile(filename);
            break;
        }

        case 6:
        {
            string filename;
            cout << "Create a File\n";
            cout << "Type a file name and path to delete it.  \n";
            cin >> filename;
            deletefile(filename);
            break;
        }
        case 7:
        {
            string filename;
            string changefilename;
            cout << "Rename a File\n";
            cout << "Type a file name of the file you want to rename.  \n";
            cin >> filename;
            cout << "Type a file name you want the file to be renamed too.  \n";
            cin >> changefilename;
            renamefile(filename, changefilename);
            break;
        }

        case 8:
        {
            string foldername;
            string changefoldername;
            cout << "Rename a Folder\n";
            cout << "Type a Folder name of the Folder you want to rename.  \n";
            cin >> foldername;
            cout << "Type a Folder name you want the Folder to be renamed too.  \n";
            cin >> changefoldername;
            renamefolder(foldername, changefoldername);
            break;
        }
        case 9:
        {
            string foldername;
            string movefoldername;
            cout << "Move a Folder\n";
            cout << "Type a folder name of the folder you want to move.  \n";
            cin >> foldername;
            cout << "Type the location you want to move the folder.  \n";
            cin >> movefoldername;
            movefolder(foldername, movefoldername);
            break;
        }
        case 10:
        {
            string filename;
            cout << "File Size\n";
            cout << "Type a file name to see the size of the file.  \n";
            cin >> filename;
            filesize(filename);
            break;
        }
        case 11:
        {
            string filename;
            cout << "File Info\n";
            cout << "Type a file name to see the info of the file.  \n";
            cin >> filename;
            fileinfo(filename);
            break;
        }
        case 12:
        {
            string filename;
            cout << "File Permissions\n";
            cout << "Type a file name to see the permissions of the file.  \n";
            cin >> filename;
            filepermissions(filename);
            break;
        }
        case 13:
        {
            string filename;
            string copyfilename;
            cout << "Copy File\n";
            cout << "Type a file name to copy.  \n";
            cin >> filename;
            cout << "Type a file name you want to copy too.  \n";
            cin >> copyfilename;
            copyfile(filename, copyfilename);
            break;
        }

        case 'X':
            cout << "Goodbye.\n";
            return 0;

        default:
            cout << selection << "is not a valid menu item.\n";

            cout << endl;
        }

    } while (selection != 0);

    return 0;
}

int ls(string directory)
{

    string directory_path = directory;
    for (const auto &file : filesystem::directory_iterator(directory_path))
    {
        cout << file.path() << endl;
    }
    return 0;
}

int makedir(string directory)
{
    string directory_name(directory);
    filesystem::create_directory(directory_name);
    cout << "created directory - " << directory_name << endl;
    return 0;
}

int deldir(string directory)
{
    filesystem::remove(directory);
    cout << "Directory deleted - " << directory << endl;
    return 0;
}

int deldirrecusive(string directory)
{
    filesystem::remove_all(directory);
    cout << "Directory deleted - " << directory << endl;
    return 0;
}

int createfile(string filename)
{
    ofstream MyFile(filename);

    // Write to the file
    MyFile << "Some sample text for the file";

    // Close the file
    MyFile.close();
    return 0;
}

int deletefile(string filename)
{
    remove(filename.c_str());
    return 0;
}

int renamefile(string filename, string changefilename)
{
    rename(filename.c_str(), changefilename.c_str());
    return 0;
}

int renamefolder(string foldername, string changefoldername)
{
    rename(foldername.c_str(), changefoldername.c_str());
    return 0;
}

int movefolder(string foldername, string movefoldername)
{
    filesystem::copy(foldername, movefoldername);
    return 0;
}
// File size
int filesize(string filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    cout << "File size = " << in.tellg() << " bytes" << endl;
}

// Information of the file
int fileinfo(string filename)
{
    filesystem::path p(filename);
    cout << "File Name = " << p.filename() << endl;
    cout << "File Extension = " << p.extension() << endl;
    cout << "File Root Name = " << p.root_name() << endl;
    cout << "File Root Directory = " << p.root_directory() << endl;
    cout << "File Root Path = " << p.root_path() << endl;
    cout << "File Relative Path = " << p.relative_path() << endl;
    cout << "File Parent Path = " << p.parent_path() << endl;
    cout << "File Stem = " << p.stem() << endl;
    return 0;
}
// File permissions
int filepermissions(string filename)
{
    filesystem::path p(filename);
    filesystem::perms perm = filesystem::status(p).permissions();
    cout << "File Permissions = " << static_cast<int>(perm) << endl;

    return 0;
}
// Copy file
int copyfile(string filename, string copyfilename)
{
    try
    {
        filesystem::copy(filename, copyfilename);
        // If copy is successful, Show the message
        cout << "File copied successfully" << endl;
    }
    catch (const filesystem::filesystem_error &ex)
    {
        cerr << "Error copying file: " << ex.what() << endl;
        return 1;
    }
    return 0;
}
