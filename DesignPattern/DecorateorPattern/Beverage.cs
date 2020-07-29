using System;

namespace DecorateorPattern
{
    abstract class Beverage
    {
        public String Description { private get; set; }= "제목 없음";

        public abstract double Cost();
        public String GetDesc()
        {
            return Description;
        }
    }
}
