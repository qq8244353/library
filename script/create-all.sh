rm -rf tmp.cpp ../all.cpp
echo '#include "all"' > tmp.cpp
oj-bundle tmp.cpp -I .. | sed 's/#line.*//' > ../all.cpp
rm -rf tmp.cpp

