using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Services
{
    public class FileService
    {
        public static List<string> ReadFromFile(string path)
        {
            List<string> lists = new List<string>();
            FileStream fStream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            while (!reader.EndOfStream)
            {
                lists.Add(reader.ReadLine());
            }
            fStream.Close();
            reader.Close();
            return lists;
        }
    }
}
