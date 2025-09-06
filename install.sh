

sudo chmod +x loca
sudo chmod +x mash
sudo chmod +x ipl
sudo chmod +x update
sudo chmod +x web
sudo chmod +x rc

echo "vim $HOME/todolist.txt" > li
sudo chmod +x li
gcc cr.c -o cr
gcc jc.c -o jc

sudo chmod +x cr
sudo chmod +x jc


sudo cp loca /usr/bin
echo "[+] loca Installed"
sudo cp mash /usr/bin
echo "[+] mash Installed"
sudo cp ipl /usr/bin
echo "[+] ipl Installed"
sudo cp update /usr/bin
echo "[+] update Installed"
sudo cp web /usr/bin
echo "[+] web Installed"
sudo cp cr /usr/bin
echo "[+] cr Installed"
sudo cp jc /usr/bin
echo "[+] jc Installed"
sudo cp li /usr/bin
echo "[+] li Installed"
echo "li Installed"
sudo cp /usr/bin/clear /usr/bin/cls
sudo cp rc /usr/bin
echo "rc Installed"
echo "rc Installed"


read -p "[*] Do you want to install Redshift? (y/n)" answer

if [[ "$answer" == "y" || "$answer" == "Y"  ]]; then
  sudo apt install redshift -y
  sudo chmod +x red
  sudo chmod +x blu
  sudo cp red /usr/bin
  sudo cp blu /usr/bin
  echo "[+] Use red to enable night light and blu to diable"
else
  echo "[+] Skipping Redshift..."
fi


read -p "[*] Do you want to install Neovim? (y/n)" answer

if [[ "$answer" == "y" || "$answer" == "Y"  ]]; then
  sudo apt install neovim -y
  mkdir $HOME/.config/nvim/
  touch $HOME/.config/nvim/init.vim
else
  echo "[+] Skipping Neovim..."
fi
echo 
sudo apt install locate -y && sudo updatedb
