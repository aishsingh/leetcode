/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) 
    {
        int houseCount = 0;

        // close all doors
        // we can keep goin right because the street is circular
        for (int i=1; i<=k; i++)
        {
            street->closeDoor();
            street->moveRight();
        }

        // open starting door, now we know that this door is the only door
        street->openDoor();

        // keep going right until back at start door, now we can calc the count of houses
        for (int i=1; i<=k; i++)
        {
            street->moveRight();

            if (street->isDoorOpen())
            {
                houseCount = i;
                break;
            }
        }

        return houseCount;
    }
};
