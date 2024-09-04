#include <unordered_map>

class Solution {
public:

    enum Direction
    {
        North=0,
        East,
        South,
        West,
    };

    class Robot
    {
        private:

            int x = 0;
            int y = 0;

            Direction facing = Direction::North;

        private:

            pair<int, int> getPositionAhead ()  // Return the next position if the robot moves forward one unit
            {
                pair<int, int> pos = {x, y};

                // position ahead depends oo the dir the robot is facing
                switch (facing)
                {
                    case Direction::North:
                        pos.second++;   // y++
                        break;

                    case Direction::East:
                        pos.first++;    // x++
                        break;

                    case Direction::South:
                        pos.second--;   // y--
                        break;

                    case Direction::West:
                        pos.first--;    // x--      
                        break;
                }

                return pos;
            }

        public:

            pair<int, int> getPos() const
            {
                return {x, y};
            }

            void turnLeft ()
            {
                facing = (facing == Direction::North) ? Direction::West : Direction(facing-1);
            }

            void turnRight ()
            {
                facing = Direction((facing+1) % 4);
            }

            bool moveForwardAvoidingObstacles (int units, unordered_map<string,int>& obstacles)
            {
                bool hasMoved = false;

                // Checking for obstacles in path ahead before moving forware one unit at a time
                for (int i=0; i<units; i++)
                {
                    // check pos ahead for obstacles
                    pair<int, int> posAhead = getPositionAhead();
                    
                    string key = to_string(posAhead.first)+","+to_string(posAhead.second);
                    if (obstacles.find(key) != obstacles.end()){
                        // obstacle found, stop moving forward
                        return hasMoved;
                    }
    
                    // move
                    x = posAhead.first;
                    y = posAhead.second;
                    hasMoved = true;
                }

                return hasMoved;
            }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        // Create a map to hold the obstacle positions as this is more efficient to query when checking if they are obstructing the robot whe moving
        unordered_map<string, int> obstacleMap;
        for (auto it : obstacles){
            string key = to_string(it[0]) + "," + to_string(it[1]); 
            obstacleMap[key]++;
        }

        Robot robot;

        int maxEuclideanDistanceSquared = 0;

        // Parse and handle requested commands
        for (auto& cmd : commands)
        {
            if (cmd == -2)                  // Turn left
            {
                robot.turnLeft();
            }
            else if (cmd == -1)             // Turn right
            {
                robot.turnRight();
            }
            else if (cmd >= 1 && cmd <= 9)  // Move forward
            {
                robot.moveForwardAvoidingObstacles(cmd, obstacleMap);

                // update max euclidean distance if required
                pair<int, int> startPos                 = {0, 0};
                pair<int, int> currentPos               = robot.getPos();
                pair<int, int> currentEuclideanDistance = calcDistance(startPos.first, startPos.second, currentPos.first, currentPos.second);

                int currentEuclideanDistanceSquared = pow(currentEuclideanDistance.first, 2) + pow(currentEuclideanDistance.second, 2); 
                if (currentEuclideanDistanceSquared > maxEuclideanDistanceSquared)
                {
                    maxEuclideanDistanceSquared = currentEuclideanDistanceSquared;
                }
            }
        }
        
        return maxEuclideanDistanceSquared;
    }

    pair<int, int> calcDistance (int startX, int startY, int endX, int endY)
    {
        int distX = abs(endX-startX);
        int distY = abs(endY-startY);

        return {distX, distY};
    }
};
