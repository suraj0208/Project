# dependencies
sudo apt-get install autoconf libtool

# installation
git clone https://github.com/pellegre/libcrafter
cd libcrafter/libcrafter
./autogen.sh 
make
sudo make install
sudo ldconfig
