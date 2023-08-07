//#include "HashTable.h"
//using namespace std;
//
//HashTable::HashTable(unsigned int _size)
//{
//    size = _size;
//
//    table = new Data[size]; // mas values
//    status = new bool[size];// mas with status 0/1
//    memset(status, 0, size);// fill all satus [0 0 0....]
//}
//int HashTable::hashFunction(Data key)
//{
//    //!KEY
//    int result = 0;
//    int sum = key.getSeries() + key.getNumber();
//    string fullName = key.getFio();
//    //!KEY
//    for (char c : fullName) {
//        sum += static_cast<int>(c);
//    }
//
//    string sumStr = to_string(sum);
//    int numDigits = sumStr.length();
//    int remainder = numDigits % 3;
//
//    if (remainder != 0) {
//        int zerosToAdd = 3 - remainder;
//        sumStr.append(zerosToAdd, '0');
//        numDigits += zerosToAdd;
//    }
//
//    int sum1 = 0;
//
//    for (int i = 0; i < numDigits; i += 3) {
//        std::string segment = sumStr.substr(i, 3);
//        int segmentNum = std::stoi(segment);
//        sum1 += segmentNum;
//    }
//
//    return sum1 % getSize();
//}
//
//int HashTable::ReHash2(int stp, int index)
//{
//    return (index + getMyK() * stp) % getSize();
//}
//
//
//
//int HashTable::ResolveColl(Data key, int hash)
//{
//    int step = 1;
//    while (true)
//    {
//        if (table[hash] == key)
//        {
//            // std::cout << "Duplicate key." << std::endl;
//            return -2;
//        }
//        int rehash = ReHash2(step, hash);
//        if (status[rehash] == 0)
//        {
//            // free item ??????? ????????? ?????? ??? ??????? ????????
//            return rehash;
//        }
//        else if (table[rehash] == key)
//        {
//            // douplicate ????????????? ????
//            // std::cout << "Duplicate key." << std::endl;
//            return -2;
//        }
//        step++;
//
//        if (step > getSize())
//        {
//            cout << "step > getSize()" << endl;
//            return -1;
//        }
//
//        if (rehash == hash)
//        {
//            // end of table 
//            return -1;
//        }
//    }
//}
//
//void HashTable::Add2(Data key)
//{
//
//    bool isRus = false;
//    for (char c : key.getFio()) {
//        if (c <= 'a' && c >= 'ÿ' || c <= 'À' && c >= 'ß') { isRus = true; }
//    }
//    if ((isRus == false) &&
//        (key.getPercent() <= 1 && key.getPercent() >= 30) &&
//        (key.getDuration() <= 1 && key.getDuration() >= 40) &&
//        (key.getSum() <= 10000 && key.getSum() >= 99999)) {
//        //mes-erroror
//    }
//    else {
//        int hash = hashFunction(key);
//        cout << "hashFunction=" << hash << "--->" << endl;
//
//        if (status[hash] == 0)
//        {
//            table[hash] = key;
//            status[hash] = 1;
//        }
//        else
//        {
//            int rehash = ResolveColl(key, hash);
//            if (rehash == -1)
//            {
//                std::cout << "No space in table." << std::endl;
//                return;
//            }
//            else if (rehash == -2)
//            {
//                std::cout << "Double." << std::endl;
//                return;
//            }
//
//            // insert in solved item 
//            table[rehash] = key;
//            status[rehash] = 1;
//            cout << endl;
//        }
//    }//end else
//}
//
//void HashTable::Print()
//{
//    for (int i = 0; i < getSize(); i++)
//    {
//        if (status[i])
//        {
//            cout << "Hash(index): " << i << " val:" << "(" << table[i].getSeries() << table[i].getNumber() << table[i].getFio() <<
//                ')  ' << table[i].getPercent() << ' ' << table[i].getSum() <<
//                ' ' << table[i].getDuration() << endl;
//        }
//    }
//}
//
//int HashTable::ResolveCollforDel(Data key, int hash) {
//    int pot = -1;
//    int step = 1;
//
//    while (step < getSize() && pot == -1) {
//        int rehash = ReHash2(step, hash);
//        if (table[rehash] == key)
//        {
//            pot = rehash;//  free item ?
//
//        }
//        else {
//            pot = -1;
//        }
//        step++;
//        cout << "step== " << step << endl;
//
//    }return pot;
//}
//
//void HashTable::Delete(Data key)
//{
//    int last;
//
//    int hash = hashFunction(key);
//
//    if (status[hash] && table[hash] == key)
//    {
//        status[hash] = false;
//        last = hash;
//    }
//    else if (status[hash]) {
//        int rehash = ResolveCollforDel(key, hash);
//        if (rehash != -1)
//        {
//            status[rehash] = false;
//            last = rehash;
//        }
//        else {
//            cout << "NOt found" << endl;
//            return;
//        }
//
//        int k;
//
//        for (int i = last + 1; i < size; i++)
//        {
//            if (status[i] && hashFunction(table[i]) == hash)
//            {
//                k = i;
//            }
//
//        }
//
//        std::cout << "Key deleted " << table[last].getFio() << endl;
//        std::cout << "Key replace " << k << endl;
//        table[last].setSeries(table[k].getSeries());
//        table[last].setNumber(table[k].getNumber());
//        table[last].setFio(table[k].getFio());
//        table[last].setDuration(table[k].getDuration());
//        table[last].setPercent(table[k].getPercent());
//
//
//        // end
//        status[k] = false;// ???????? ????????? ?????? ??? ?????????
//        status[last] = true; // posle perenosa on snova zapolnen
//        //std::cout << "!!!!!!LAST"<< table[rehash].tripInt<<endl;       
//    }
//}
//
//int HashTable::Find2(Data key)
//{
//    int hash = hashFunction(key);
//    int rehash = hash;
//    int step = 1;
//    cout << "firs ind " << rehash << endl;
//
//    while (status[rehash] == 1)
//    {
//        if (table[rehash] == key)
//        {
//            //std::cout << "Found hash: " << rehash;
//            return rehash;
//        }
//        //cout<<rehash<<endl;
//
//        rehash = ReHash2(step, hash);
//        step++;
//        cout << "find in :" << rehash << endl;
//        if (step >= size)
//            break;
//    }
//    std::cout << "Key not found";
//
//};
//void  HashTable::changeLastIndex(Data key, int delIndex) {
//    int elemIndex = Find2(key);
//    if (elemIndex != -1) {
//        table[elemIndex].setIndex(delIndex);
//    }
//}