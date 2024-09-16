/** My solution posted on Leetode
 *  https://leetcode.com/problems/convert-the-temperature/solutions/5793685/c-with-rounding-to-3-decimals  
 */

class Solution {
public:
    vector<double> convertTemperature(double celsius) 
    {
        // Kelvin = Celsius + 273.15
        double temp_kel = roundTo3Decimals(celsius + 273.15);

        // Fahrenheit = Celsius * 1.80 + 32.00
        double temp_fah = roundTo3Decimals(celsius * 1.80f) + 32;

        return {temp_kel, temp_fah};
    }

    double roundTo3Decimals(double value)
    {
        return round(value * 1000.0f) / 1000.0f;
    }
};
