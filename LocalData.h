#pragma once

#include <iostream>

class LocalData {
public:
    static const char* Load(const char* file)
    {
        std::ifstream ifs(file);

        //�Ǎ��T�C�Y�𒲂ׂ�B
        ifs.seekg(0, std::ios::end);
        long long int size = ifs.tellg();
        ifs.seekg(0);

        //�ǂݍ��񂾃f�[�^��char�^�ɏo�͂���
        std::shared_ptr<T> data = std::make_shared<T>();
        ifs.read((char*)data, sizeof(T));

        return data;
    }

    template<typename T>
    static void Save(const char* file, T& data, const char* path = NULL, bool fenc = false)
    {
        std::ifstream ifs(file);

        //�ǂݍ��񂾃f�[�^��char�^�ɏo�͂���
        std::shared_ptr<T> data = std::make_shared<T>();
        ifs.write((char*)data, sizeof(T));

        return data;
    }

    static void Delete(const char* file, const char* path = NULL);
};
