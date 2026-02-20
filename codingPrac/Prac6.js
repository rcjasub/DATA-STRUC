// Handle API responses for a web app
// 5 bugs to fix!

const APIHandler = {
    fetchUserData: async function(userId) {
        const mockData = {
            id: userId,
            name: 'Jane Seller',
            shop: {
                name: 'Vintage Finds',
                listings: [
                    {id: 1, title: 'Mug', price: 15},
                    {id: 2, title: 'Scarf', price: 25}
                ]
            }
        };
        return new Promise(resolve => setTimeout(() => resolve(mockData), 100));
    },
    
    getUserName: async function(userId) { 
        const data = await this.fetchUserData(userId);
        return data.name;
    },
    
    getShopName: async function(userId) {
        const data = await this.fetchUserData(userId);  
        return data.shop.name;
    },
    
    getInventoryValue: async function(userId) {
        const data = await this.fetchUserData(userId);
        //rember to access other json data we must do dot notation data.some
        return data.shop.listings.reduce((sum, item) => sum + item.price, 0);
    },
    
    getListingTitles: async function(userId) {
        const data = await this.fetchUserData(userId);
        return data.shop.listings.map(item => item.title);
    }
};

// Tests
async function runTests() {
    console.log(await APIHandler.getUserName(123) === 'Jane Seller');
    console.log(await APIHandler.getShopName(123) === 'Vintage Finds');
    console.log(await APIHandler.getInventoryValue(123) === 40);
    console.log((await APIHandler.getListingTitles(123)).join(',') === 'Mug,Scarf');
}

runTests();