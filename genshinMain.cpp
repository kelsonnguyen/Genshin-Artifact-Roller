#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

// Struc for artifact information
struct Artifact
{
    string type, mainStat;
    pair<string, double> line1, line2, line3, line4;
};

// Function definitions
void displayArtifact(Artifact);
void displayChoices();

// Main
int main()
{
    srand(time(nullptr)); // for artifact rolling
    // Variables
    vector<Artifact> artifactList; 
    string inputStop;
    int artiTypeIndex, artiLineIndex; 
    int choice = 0;
    string artifactTypes[] = {"Flower of Life", "Plume of Death", 
    "Sands of Eon", "Goblet of Eonothem", "Circlet of Logos"};

    // Multimaps for artifact lines    
    multimap<string, double> potLines;

    potLines.insert(pair<string, double>("CRIT Rate", 2.7));
    potLines.insert(pair<string, double>("CRIT Damage", 5.4));
    potLines.insert(pair<string, double>("Energy Recharge", 4.5));
    potLines.insert(pair<string, double>("DEF", 5.8));
    potLines.insert(pair<string, double>("HP", 4.7));
    potLines.insert(pair<string, double>("ATK", 4.7));

    // Menu beginning   
    cout << "Welcome to the Artifact Roller!";

    // Begin rolling
    while (choice != 3)
    {
        displayChoices();
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                // Begin rolling for an artifact
                set<pair<string, double>> selectedLines;

                Artifact randomArti;
                artiTypeIndex = rand() % 4;
                randomArti.type = artifactTypes[artiTypeIndex];

                while (selectedLines.size() != 4)
                {
                    artiLineIndex = rand() % potLines.size();
                    auto potLineIter = next(potLines.begin(), artiLineIndex);
                    pair<string, double> selectedLine = *potLineIter;

                    if (selectedLines.count(selectedLine) == 0)
                    {
                        selectedLines.insert(selectedLine);
                    }
                }

                // Set lines for artifact
                auto setLineIter = selectedLines.begin();
                randomArti.line1 = *setLineIter;
                randomArti.line2 = *++setLineIter;
                randomArti.line3 = *++setLineIter;
                randomArti.line4 = *++setLineIter;

                // Push back the artifact into vector
                artifactList.push_back(randomArti);
                displayArtifact(randomArti);

                break;
            }

            case 2:
            {
                for (const auto& i : artifactList)
                {
                    displayArtifact(i);
                }

                break;
            }

            case 3:
            {
                cout << "\nThank you!";
                break;
            }

            default:
            {
                cout << "\nPlease input a valid option: ";

                break;
            }
        }
    }

    return 0;
}

void displayChoices()
{
    cout << "\nType 1 to roll\n"
        << "2 to display all artifacts\n"
        << "3 to stop\n"
        << "Choice: ";
}

// Function to display artifact
void displayArtifact(Artifact artifact)
{
    cout << "\nArtifact Type: " << artifact.type << endl;

    cout << "   " << artifact.line1.first << "+" 
        << artifact.line1.second << "%" << endl;
    cout << "   " << artifact.line2.first << "+" 
        << artifact.line2.second << "%" << endl;
    cout << "   " << artifact.line3.first << "+" 
        << artifact.line3.second << "%" << endl;
    cout << "   " << artifact.line4.first << "+"    
    << artifact.line4.second << "%\n\n";
}