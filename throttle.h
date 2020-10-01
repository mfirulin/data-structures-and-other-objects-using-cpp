#ifndef THROTTLE_H
#define THROTTLE_H

namespace CPP_data_structure
{
    class Throttle
    {
    public:
        Throttle();
        Throttle(int top_position);
        Throttle(int top_position, int position);

        void shut_off();
        void shift(int amount);
        int top_position() const;
        int position() const;
        double flow() const;
        bool is_on() const;
        bool is_half() const;


    private:
        int pos = 0;
        int top_pos = 0;
    };
}

#endif