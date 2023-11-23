
#include "stdafx.h"
#include "LocalData.h"

class LocalData
{
public:
    template<typename T>
    static T Load(const char* file, const char* path = NULL, bool fenc = false);

    template<typename T>
    static void Save(const char* file, T& data, const char* path = NULL, bool fenc = false);

    static void Delete(const char* file, const char* path = NULL);
};

    {
        try
        {
            if (path == null)
            {
                path = Application.dataPath; //Application.persistentDataPath; //デバッグしやすくした、製品ではpersistentDataPathを使う事。
            }

            //ファイルがなかったらnullで返す
            if (!File.Exists(path + "/" + file))
            {
                return default(T);
            }

            var arr = File.ReadAllBytes(path + "/" + file);
#if RELEASE
            arr = AesDecrypt(arr);
#else
            if (fenc)
            {
                arr = AesDecrypt(arr);
            }
#endif
            string json = Encoding.UTF8.GetString(arr);
            return JsonUtility.FromJson<T>(json);
        }
        catch (Exception ex)
        {
            Debug.LogError($"Load{file}");
            Debug.LogError(ex.Message);
        }
        return default(T);
    }



    {
        try
        {
            if (path == null)
            {
                path = Application.dataPath; //Application.persistentDataPath; //デバッグしやすくした、製品ではpersistentDataPathを使う事。
            }

            var json = JsonUtility.ToJson(data);
            byte[] arr = Encoding.UTF8.GetBytes(json);
#if RELEASE
            arr = AesEncrypt(arr);
#else
            if (fenc)
            {
                arr = AesEncrypt(arr);
            }
#endif
            var pathes = (path + "/" + file).Split('/').ToList();
            pathes.RemoveAt(pathes.Count - 1);
            var dir = string.Join("/", pathes);
            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }
            File.WriteAllBytes(path + "/" + file, arr);
        }
        catch (Exception ex)
        {
            Debug.LogError($"Save{file}");
            Debug.LogError(ex.Message);
        }
    }



    {
        if (path == null)
        {
            path = Application.persistentDataPath;
        }

        //ファイルがなかったらnullで返す
        if (!File.Exists(path + "/" + file))
        {
            return;
        }

        File.Delete(path + "/" + file);
    }