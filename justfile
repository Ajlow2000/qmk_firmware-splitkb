elora:
    qmk compile -kb splitkb/elora -km ajlow2000
    cp ./keyboards/splitkb/elora/keymaps/ajlow2000/* ~/repos/ajlow2000_keebs/elora/qmk/
    cp ./splitkb_elora_rev1_ajlow2000.uf2 ~/repos/ajlow2000_keebs/elora/firmware/

kyria:
    qmk compile -kb splitkb/kyria/rev3 -km ajlow2000 -e CONVERT_TO=liatris
    cp ./keyboards/splitkb/kyria/keymaps/ajlow2000/* ~/repos/ajlow2000_keebs/kyria/qmk/
    cp ./splitkb_kyria_rev3_ajlow2000.uf2 ~/repos/ajlow2000_keebs/kyria/firmware/

