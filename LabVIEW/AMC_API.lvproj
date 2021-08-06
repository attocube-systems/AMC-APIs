<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="16008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="access" Type="Folder" URL="../access">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="control" Type="Folder" URL="../control">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="description" Type="Folder" URL="../description">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="diagnostic" Type="Folder" URL="../diagnostic">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="move" Type="Folder" URL="../move">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="res" Type="Folder" URL="../res">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="rtin" Type="Folder" URL="../rtin">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="rtout" Type="Folder" URL="../rtout">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="status" Type="Folder" URL="../status">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="system" Type="Folder" URL="../system">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="TCPHandler" Type="Folder" URL="../TCPHandler">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="LabVIEW_Example.vi" Type="VI" URL="../../examples/LabVIEW_Example.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="ex_CorrectErrorChain.vi" Type="VI" URL="/&lt;vilib&gt;/express/express shared/ex_CorrectErrorChain.vi"/>
				<Item Name="subDisplayMessage.vi" Type="VI" URL="/&lt;vilib&gt;/express/express output/DisplayMessageBlock.llb/subDisplayMessage.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
