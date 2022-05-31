#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>

using namespace std;

vector<int> generate_rand(void)
{
    srand(time(0));
   vector<int> v1;
   for(int i=0;i<20;i++)
    v1.push_back(rand()%2);
   cout<<"Generated Data Sequence>\n";
   for(auto x:v1)
    cout<<x<<" ";
   cout<<"\n";
   return v1;

}


vector<int> generate_rand_sub_seq(void)
{

    srand(time(0));
    vector<int> v1;
    cout<<"Choose a sub-sequence>\n"
        <<"1. 8 consecutive zeroes (B8ZS and HDB3)"
        <<"\n2. 4 consecutive zeroes (HDB3)\n> ";

   bool valid_flag=false;
   int choice;
   while(!valid_flag)
   {
       cin>>choice;

       if(choice==1)
       {

            system("cls");
           for(int i=0;i<30;i++)
           {
               v1.push_back(rand()%2);
               if(i==5)
               {
                   while(i<=13)
                   {
                          v1.push_back(0);
                          i++;
                   }

               }
               if(i==18)
               {
                   while(i<=26)
                   {
                       v1.push_back(0);
                       i++;
                   }
               }
           }
        valid_flag=true;
       }
       else if(choice==2)
       {
            system("cls");
           for(int i=0;i<30;i++)
           {
               v1.push_back(rand()%2);
               if(i%9==0)
               {


               int fix=i;
                   while(i<=fix+4)
                   {

                       v1.push_back(0);
                       i++;
                   }


               }
           }
           valid_flag=true;

       }
       else
       {
           cout<<"Please enter a valid number!!\n> ";
       }
   }
   cout<<"Generated Data Sequence>\n";
   for(auto x:v1)
    cout<<x<<" ";
   cout<<"\n";

   return v1;
}


void nrz_encoding_L(vector<int> v1)
{





    int window_width=2000;
    int window_height=1300;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "NRZ-L Encoding");

        sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }

    sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("NRZ-L Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-200,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);

     int off=100;




    vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));

    int mid_x=window_height/2;
    int mid_y=window_height/2;

    int line_length=100;
    int x;
    int y;
    vector<sf::Vertex> lines;
    if(v1[0]==1)
    {
        x=0;
        y=mid_y-off;

        lines.push_back(sf::Vector2f(x,y));
        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));
    }
    else
    {
        x=0;
        y=mid_y;

         lines.push_back(sf::Vector2f(x,y));
        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));
    }
    int prev=v1[0];
    for(int i=1;i<v1.size();i++)
    {
        if(prev!=v1[i])
        {
            if(v1[i]==1)
                y-=off;
            else
                y+=off;
        }

         lines.push_back(sf::Vector2f(x,y));
        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));
        prev=v1[i];

    }

      while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
        window.draw(&lines[0],lines.size(),sf::LinesStrip);
         for(int i=0,f_x=line_length/2-6;i<v1.size();i++)
        {
            if(v1[i]==0)
            {
                text_0.setPosition(f_x,window_height/2-off-50);
                f_x+=line_length;
                window.draw(text_0);
            }
            else
            {
                text_1.setPosition(f_x,window_height/2-off-50);
                f_x+=line_length;
                window.draw(text_1);
            }
        }
        window.draw(text_name);
        window.draw(text_stream);

        window.display();
    }

}

void nrz_encoding_I(vector<int> v1)
{
    int window_width=2000;
    int window_height=1300;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "NRZ-I Encoding");
      sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }
       sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("NRZ-I Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-200,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);


    vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));


    int mid_y=window_height/2;
    int off=100;
    int line_length=100;
    int x=5;
    int y=mid_y-off;

    vector<sf::Vertex> lines;
     lines.push_back(sf::Vector2f(x,y));

    if(v1[0]==1)
    {

        y+=off;

        lines.push_back(sf::Vector2f(x,y));
        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));
    }
    else
    {

        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));
    }
    for(int i=1;i<v1.size();i++)
    {
       if(v1[i]==1)
       {
           if(y==mid_y)
            y-=off;
           else
            y+=off;
       }

         lines.push_back(sf::Vector2f(x,y));
        x+=line_length;

        lines.push_back(sf::Vector2f(x,y));


    }

      while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
        window.draw(&lines[0],lines.size(),sf::LinesStrip);
          for(int i=0,f_x=line_length/2-6;i<v1.size();i++)
        {
            if(v1[i]==0)
            {
                text_0.setPosition(f_x,window_height/2-off-50);
                f_x+=line_length;
                window.draw(text_0);
            }
            else
            {
                text_1.setPosition(f_x,window_height/2-off-50);
                f_x+=line_length;
                window.draw(text_1);
            }
        }
           window.draw(text_name);
        window.draw(text_stream);

        window.display();
    }

}


void manchester_encoding(vector<int> v1)
{
    int window_width=2000;
    int window_height=1300;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Manchester Encoding");

        sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }
       sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("Manchester Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-200,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);


    vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));


    int mid_y=window_height/2;
    int off=100;
    int line_length=50;
    int x=0;
    int y;

    vector<sf::Vertex> lines;




    for(int i=0;i<v1.size();i++)
    {


          if(v1[i]==0)
          {
              y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
          }
          else
          {
              y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));

          }


    }

      while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
        window.draw(&lines[0],lines.size(),sf::LinesStrip);
         for(int i=0,f_x=line_length-6;i<v1.size();i++)
        {
            if(v1[i]==0)
            {
                text_0.setPosition(f_x,window_height/2-off-50);
                f_x+=2*line_length;
                window.draw(text_0);
            }
            else
            {
                text_1.setPosition(f_x,window_height/2-off-50);
                f_x+=2*line_length;
                window.draw(text_1);
            }
        }

           window.draw(text_name);
        window.draw(text_stream);

        window.display();
    }
}



void  diff_manchester_encoding(vector<int> v1)
{
    int window_width=2000;
    int window_height=1300;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Differential Manchester Encoding");


  sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }

       sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("Differential Manchester Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-300,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);
     vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));

    int mid_y=window_height/2;
    int off=100;
    int line_length=50;
    int x=5;
    int y=mid_y-off;

    vector<sf::Vertex> lines;

     int prev_seq=1;
     lines.push_back(sf::Vector2f(x,y));
     v1[0]=1;

    for(int i=0;i<v1.size();i++)
    {


          if(v1[i]==1)
          {
              if(prev_seq==0)
              {
                 y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              prev_seq=1;
              }
              else
              {


              y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              prev_seq=0;
              }

          }
          else
          {
              if(prev_seq==0)
              {


             y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              prev_seq=0;

              }
              else
              {
                      y=mid_y+off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              y=mid_y-off;
              lines.push_back(sf::Vector2f(x,y));
              x+=line_length;
              lines.push_back(sf::Vector2f(x,y));
              prev_seq=1;
              }

          }


    }

      while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
        window.draw(&lines[0],lines.size(),sf::LinesStrip);
         for(int i=0,f_x=line_length-6;i<v1.size();i++)
        {
            if(v1[i]==0)
            {
                text_0.setPosition(f_x,window_height/2-off-50);
                f_x+=2*line_length;
                window.draw(text_0);
            }
            else
            {
                text_1.setPosition(f_x,window_height/2-off-50);
                f_x+=2*line_length;
                window.draw(text_1);
            }
        }
           window.draw(text_name);
        window.draw(text_stream);
        window.display();
    }
}


void  ami_encoding(vector<int> v1)
{
    cout<<"Choose the type of scrambling>\n"
        <<"1.B8ZS\n"
        <<"2.HDB3\n> ";

        int choice;
        bool valid_flag=false;

        while(!valid_flag)
        {
            cin>>choice;

           if(choice==1)
           {
                     valid_flag=true;

                    int window_width=1650;
                    int window_height=1300;
                    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "AMI-B8ZS Encoding");
                sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }
                           sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("AMI-B8ZS Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-200,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);

      vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));



                    int mid_y=window_height/2;
                    int off=100;
                    int line_length=50;
                    int x=5;
                    int y=mid_y-off;
                    int prev=1;
                    int prev_pos=1;

                    vector<sf::Vertex> lines;
                    bool valid_out=false;
                    for(int i=0;i<v1.size();i++)
                    {
                         bool cons_flag;
                     int ver_i=i;
                     if(i>v1.size()-8)
                     cons_flag=false;
                     else
                     cons_flag=true;
                        if(i<=v1.size()-8&&v1[i]==0&&(prev==1||prev==0))
                       {

                        while(ver_i<i+8)
                        {
                            if(v1[ver_i]!=0)
                            {
                                cons_flag=false;
                                break;
                            }
                            ver_i++;
                        }
                        if(cons_flag)
                        {
                            valid_out=true;
                            if(prev==1)
                            {
                                y=mid_y;
                                for(int j=0;j<4;j++,x+=line_length)
                                    lines.push_back(sf::Vector2f(x,y));
                                    x-=line_length;
                                y=mid_y-off;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                 lines.push_back(sf::Vector2f(x,y));
                                 y=mid_y+off;
                                   lines.push_back(sf::Vector2f(x,y));
                                   x+=line_length;
                                  lines.push_back(sf::Vector2f(x,y));
                                    y=mid_y;
                                    lines.push_back(sf::Vector2f(x,y));
                                    x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                    y=mid_y+off;
                                   lines.push_back(sf::Vector2f(x,y));
                                    x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                      y=mid_y-off;
                                 lines.push_back(sf::Vector2f(x,y));
                                  x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                    prev_pos=1;

                            }
                            else
                            {
                                y=mid_y;
                                for(int j=0;j<4;j++,x+=line_length)
                                    lines.push_back(sf::Vector2f(x,y));
                                       x-=line_length;
                                 y=mid_y+off;
                                   lines.push_back(sf::Vector2f(x,y));
                                    x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                  y=mid_y-off;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                     y=mid_y;
                                   lines.push_back(sf::Vector2f(x,y));
                                   x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                     y=mid_y-off;
                                 lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                     y=mid_y+off;
                                   lines.push_back(sf::Vector2f(x,y));
                                    x+=line_length;
                                    lines.push_back(sf::Vector2f(x,y));
                                    prev_pos=0;

                            }

                            i+=7;

                        }
                        else
                        {
                                       if(v1[i]==1)
                            {
                                if(prev==1)
                                {
                                    y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                      prev_pos=0;
                                }
                                else if(prev==0)
                                {
                                    y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                }
                                else
                                {
                                    if(prev_pos==1)
                                    {
                                         y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                       prev_pos=0;
                                    }
                                    else
                                    {
                                        y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                    }

                                }
                            }
                            else
                            {
                                y=mid_y;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=3;

                            }
                        }

                        }
                        else
                        {
                            if(v1[i]==1)
                            {
                                if(prev==1)
                                {
                                    y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                      prev_pos=0;
                                }
                                else if(prev==0)
                                {
                                    y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                }
                                else
                                {
                                    if(prev_pos==1)
                                    {
                                         y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                       prev_pos=0;
                                    }
                                    else
                                    {
                                        y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                    }

                                }
                            }
                            else
                            {
                                y=mid_y;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=3;

                            }
                        }


                    }
                    if(valid_out)
                    {
                          while (window.isOpen())
                        {
                        sf::Event event;
                    while (window.pollEvent(event))
                    {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    }

                    window.clear();
                    window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
                    window.draw(&lines[0],lines.size(),sf::LinesStrip);
                     for(int i=0,f_x=line_length/2-6;i<v1.size();i++)
                        {
                        if(v1[i]==0)
                        {
                        text_0.setPosition(f_x,window_height/2-off-50);
                        f_x+=line_length;
                        window.draw(text_0);
                        }
                        else
                        {
                        text_1.setPosition(f_x,window_height/2-off-50);
                        f_x+=line_length;
                        window.draw(text_1);
                        }
                        }
                           window.draw(text_name);
                           window.draw(text_stream);
                    window.display();
                        }

                    }
                    else
                        cout<<"There was no valid sequence to use B8ZS!!\nPlease restart the program!!";

           }
           else if(choice==2)
           {
                valid_flag=true;

               int window_width=1600;
                    int window_height=1300;
                    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "AMI-HDB3 Encoding");
                       sf::Font font;

    if(!font.loadFromFile("res/consola.ttf"))
    {
        cout<<"Error loading file\n";
    }
    sf::Text text_0;
    sf::Text text_1;
    sf::Text text_name;
    sf::Text text_stream;
    text_0.setFont(font);
    text_1.setFont(font);
    text_name.setFont(font);
    text_stream.setFont(font);
    text_0.setString("0");
    text_1.setString("1");
    text_name.setString("AMI-HDB3 Encoding");
    string s1;
    for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==0)
                s1+="0";
            else
                s1+="1";
        }

    text_stream.setString("Data Stream - "+s1);
    text_name.setPosition(window_width/2-200,window_height/2-500);
    text_stream.setPosition(window_width/2-300,window_height/2-400);


      vector<sf::Vertex> line_mid(2);
    line_mid.push_back(sf::Vector2f(0, window_height/2));
    line_mid.push_back( sf::Vector2f(window_width, window_height/2));

                    int mid_y=window_height/2;
                    int off=100;
                    int line_length=50;
                    int x=5;
                    int y;
                    int prev=1;
                    int prev_pos=1;
                    int count_n=0;
                    vector<sf::Vertex> lines;
                    bool valid_out=false;

                    for(int i=0;i<v1.size();i++)
                    {
                        bool valid_seq;

                        if(i>v1.size()-4)
                            valid_seq=false;
                        else
                            valid_seq=true;

                        int ver_i=i;


                        if(i<=v1.size()-4&&v1[i]==0&&(prev==1||prev==0))
                       {

                        while(ver_i<i+4)
                        {
                            if(v1[ver_i]!=0)
                            {
                                valid_seq=false;
                                break;
                            }
                            ver_i++;
                        }

                        if(valid_seq)
                        {
                            valid_out=true;
                            if(prev==1)
                            {
                                if(count_n%2==0)
                                {
                                     y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                        y=mid_y;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                      prev_pos=0;
                                }
                                else
                                {
                                     y=mid_y;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                        y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                }
                            }
                            else
                            {

                                if(count_n%2==0)
                                {
                                      y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                        y=mid_y;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                     prev_pos=1;
                                }
                                else
                                {
                                      y=mid_y;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                       x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                        y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                       prev_pos=0;
                                }
                            }

                            count_n=0;
                            i+=3;
                        }
                        else
                        {
                             if(v1[i]==1)
                            {
                                if(prev==1)
                                {
                                    y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                      prev_pos=0;
                                }
                                else if(prev==0)
                                {
                                    y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                }
                                else
                                {
                                    if(prev_pos==1)
                                    {
                                         y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                       prev_pos=0;
                                    }
                                    else
                                    {
                                        y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                    }

                                }
                                count_n++;
                            }
                            else
                            {
                                y=mid_y;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=3;

                            }


                        }//else


                    }
                    else
                    {

                        if(v1[i]==1)
                            {
                                if(prev==1)
                                {
                                    y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                      prev_pos=0;
                                }
                                else if(prev==0)
                                {
                                    y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                }
                                else
                                {
                                    if(prev_pos==1)
                                    {
                                         y=mid_y+off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=0;
                                       prev_pos=0;
                                    }
                                    else
                                    {
                                        y=mid_y-off;
                                     lines.push_back(sf::Vector2f(x,y));
                                     x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=1;
                                       prev_pos=1;
                                    }

                                }
                                count_n++;
                            }
                            else
                            {
                                y=mid_y;
                                 lines.push_back(sf::Vector2f(x,y));
                                 x+=line_length;
                                      lines.push_back(sf::Vector2f(x,y));
                                      prev=3;

                            }

                    }

           }//for
            if(valid_out)
                    {
                          while (window.isOpen())
                        {
                        sf::Event event;
                    while (window.pollEvent(event))
                    {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    }

                    window.clear();
                    window.draw(&line_mid[0],line_mid.size(),sf::LinesStrip);
                    window.draw(&lines[0],lines.size(),sf::LinesStrip);
                     for(int i=0,f_x=line_length/2-6;i<v1.size();i++)
                        {
                        if(v1[i]==0)
                        {
                        text_0.setPosition(f_x,window_height/2-off-50);
                        f_x+=line_length;
                        window.draw(text_0);
                        }
                        else
                        {
                        text_1.setPosition(f_x,window_height/2-off-50);
                        f_x+=line_length;
                        window.draw(text_1);
                        }
                        }
                         window.draw(text_name);
                           window.draw(text_stream);
                    window.display();
                        }

                    }
                    else
                        cout<<"There was no valid sequence to use HDB3!!\nPlease restart the program!!";


           }
           else
           {
            cout<<"Please enter a valid number!!\n> ";
           }
        }
}



string lcs(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();

    int L[m+1][n+1];


    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }


    int index = L[m][n];
    string lcs(index+1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {

        if (s1[i-1] == s2[j-1])
        {

            lcs[index-1] = s1[i-1];
            i--;
            j--;

            index--;
        }


        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    return lcs;
}


string LPS(string &s1)
{
    string  s2 = s1;
    reverse(s2.begin(), s2.end());


    return lcs(s1, s2);
}







int main()
{

    cout<<"Choose the type of data sequence to be generated>"
     <<"\n1.Random Sequence"
     <<"\n2.Random Sequence with fixed sub-sequence \n> ";

     int choice;

     vector<int> seq;

     bool valid_flag=false;
     while(!valid_flag)

    {

     cin>>choice;
     switch(choice)
     {
         case 1 :  system("cls");
                  seq=generate_rand();
                   valid_flag=true;
         break;
         case 2 :  system("cls");
                  seq=generate_rand_sub_seq();
                    valid_flag=true;
         break;
         default : cout<<"Please enter a valid number!!\n> ";

     }

    }

    cout<<"Choose the type of Encoding>\n"
         <<"1.NRZ-L\n"
         <<"2.NRZ-I\n"
         <<"3.Manchester\n"
         <<"4.Differential Manchester\n"
         <<"5.AMI\n> ";

         valid_flag=false;
         while(!valid_flag)
         {
             cin>>choice;
             switch(choice)
             {


             case 1 :   system("cls");
                       nrz_encoding_L(seq);
                       valid_flag=true;
             break;

             case 2 :  system("cls");
                       nrz_encoding_I(seq);
                       valid_flag=true;
             break;

             case 3 :  system("cls");
                       manchester_encoding(seq);
                       valid_flag=true;
             break;

             case 4 :  system("cls");
                       diff_manchester_encoding(seq);
                       valid_flag=true;
             break;

             case 5 :  system("cls");
                      ami_encoding(seq);
                      valid_flag=true;
             break;

             default : cout<<"Please enter a valid number!!\n> ";

             }

         }


         string s1;
         cout<<"\n\nOriginal Sequence > ";
    for(auto x:seq)
    {
         s1+=48+x;
         cout<<x;
    }

    cout << "\nLongest Palindromic Subsequence > "<<LPS(s1);
     cout<<"\n\n";







    return 0;
}
