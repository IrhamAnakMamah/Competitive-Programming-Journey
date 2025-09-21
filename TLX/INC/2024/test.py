def update(inventaris, barang, jumlah):
  inventaris[barang] = jumlah

gudang = {"Apel": 50, "Jeruk": 20}
update(gudang, "Alpukat", 40)
print(gudang)