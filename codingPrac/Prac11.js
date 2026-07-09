class VersionControlSystem {
    constructor(){
        this.shops = new Map();
    }

    update(shop_id, text){
        if(!text) throw new Error("Text cannot be empty");
        if(!this.shops.has(shop_id))
        {
            this.shops.set(shop_id, []); // 
        }

        this.shops.get(shop_id).push(text);
    }

    get_current(shop_id){

        if(!this.shops.get(shop_id)) throw new Error(`Shop ${shop_id} does not exits`);

        const version = this.shops.get(shop_id); // get a hold of the arr in the map
        return version[version.length - 1]; // gives the position at that string

        //can also be written like
        //return this.shops.get(shop_id).at(-1);
    }

    get_version(shop_id, version_number)
    {
        if(!this.shops.get(shop_id)) throw new Error(`Shop ${shop_id} does not exits`);

         const versions = this.shops.get(shop_id);

         if(version_number < 1 || version_number > versions.length){
          throw new Error(`Version ${version_number} is out of bound`);
         }

        return this.shops.get(shop_id)[version_number - 1]; //grab the key and return the text in that position
    }

    rollback(shop_id, versionNumber)
    {
        if(!this.shops.has(shop_id))
        {
            throw new Error(`Shop ${shop_id} does not exist`);
        }

        const versions = this.shops.get(shop_id); // to get length

        if(versionNumber < 1 || versionNumber > versions.length){
          throw new Error(`Version ${versionNumber} is out of bound`);
        }

        const oldTxt = this.get_version(shop_id, versionNumber); // grab the text on that position in that key
        this.update(shop_id, oldTxt); // push this old txt to the end like any new update
    }

}